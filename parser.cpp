#include "parser.h"
#include "instructionerror.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

Parser::Parser(): m_source(source::input)
{

}

Parser::Parser(const std::string& filename): m_filename(filename), m_source(source::file)
{

}

void Parser::open_stream()
{
    if (in == nullptr) //if in is not nullptr, then parsing error appeared and function is called not for the first time
    {
        if (m_source == source::file)
        {
            file.open(m_filename);
        }
        in = (m_source == source::file) ? &file : &std::cin;
        if (!*in)
        {
            m_good = 0;
            m_parsed = 1;
            throw std::runtime_error("Couldn't open file.");
        }
    }
}

void Parser::exec(std::queue<const Instruction*>& instr)
{
    open_stream();
    read_file();
    parse_tokens(instr);
}

bool Parser::parsed() const
{
    return m_parsed;
}

void Parser::read_file()
{
    if (contents.empty() && m_parsed == 0)
    {
        if (m_source == source::file)
        {
            contents.assign((std::istreambuf_iterator<char>(*in)), std::istreambuf_iterator<char>());
        }
        else
        {
            while (1)
            {
                contents += static_cast<char>(in->get());
                if (contents.size() >= 2 && contents[contents.size() - 2] == ';' && contents[contents.size() - 1] == ';') //if reading form standar input, ;; is equal to eof
                {
                    break;
                }
            }
        }
        if (contents.back() != '\n') //is needed for token_pattern regex
        {
            contents.push_back('\n');
        }
    }
}

void Parser::parse_tokens(std::queue<const Instruction*>& instr)
{
    std::smatch tokens;
    std::regex token_pattern("(.*)\n");
    std::string line_instr;

    while (std::regex_search(contents, tokens, token_pattern))
    {
        ++m_line;
        InstructionError::set_line(m_line); //show specified line in exception texts
        line_instr = tokens[1];
        contents = tokens.suffix().str();
        try
        {
            parse_instructions(instr, line_instr); //pass single line with instruction and its parameters and comments
        }
        catch (...)
        {
            m_good = 0;
            throw;
        }
    }
    m_parsed = 1;
    InstructionError::set_line(0); //do not show lines in exception texts
}

void Parser::parse_instructions(std::queue<const Instruction*>& instr, std::string str)
{
    std::regex instr_pattern("^([^ ;]*)(( ([^ ;]+))*)[ ]?(;.*)?$"); //instruction params ;comments
    std::string instruction;
    std::vector<std::pair<std::string, std::string>> params;
    std::regex_token_iterator<std::string::iterator> it(str.begin(), str.end(), instr_pattern, {1});
    std::regex_token_iterator<std::string::iterator> rend;
    if (it != rend)
    {
        instruction = it->str();
    }
    else
    {
        throw ParseError(std::string("Line ") + std::to_string(m_line) + " is not an instruction.");
    }
    it = std::regex_token_iterator<std::string::iterator>(str.begin(), str.end(), instr_pattern, {2});
    if (it != rend)
    {
        if (it->str().size() > 0)
        {
            parse_params(params, it->str()); //pass only parameters
        }
        if (instruction.size() > 0 || params.size() > 0)
        {
            instr.push(m_if.createInstruction(instruction, params));
        }
    }
}

void Parser::parse_params(std::vector<std::pair<std::string, std::string>> &params, std::string str)
{
    std::regex params_pattern(R"(^( ([^\(]+)\(([^\)]+)\))*$)"); //general parameters pattern
    std::regex param_pattern(R"( ([^\(]+)\(([^\)]+)\))"); //pattern to get single parameters
    std::regex n_value_pattern(R"([-]?[\d]+)"); //pattern for integer numbers
    std::regex z_value_pattern(R"([-]?[\d]+\.[\d]+)"); //pattern for real numbers
    std::string value_type;
    std::string value;

    if (std::regex_match(str, params_pattern))
    {
        std::regex_token_iterator<std::string::iterator> it(str.begin(), str.end(), param_pattern, {1, 2});
        std::regex_token_iterator<std::string::iterator> rend;
        while (it != rend)
        {
            value_type = it->str();
            ++it;
            value = it->str();
            if (value_type == "float" || value_type == "double")
            {
                if (std::regex_match(value, z_value_pattern))
                {
                    params.push_back(std::make_pair(value_type, value));
                }
                else
                {
                    throw BrokenFloat();
                }
            }
            else
            {
                if (std::regex_match(value, n_value_pattern))
                {
                    params.push_back(std::make_pair(value_type, value));
                }
                else
                {
                    throw BrokenInteger();
                }
            }
            ++it;
        }
    }
    else
    {
        throw ParseError("Broken or unknown parameter.");
    }
}

Parser::operator bool() const
{
    return m_good;
}
