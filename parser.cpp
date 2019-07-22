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
    if (in == nullptr)
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
        contents.assign((std::istreambuf_iterator<char>(*in)), std::istreambuf_iterator<char>());
        if (contents.back() != '\n')
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
        InstructionError::set_line(m_line);
        line_instr = tokens[1];
        contents = tokens.suffix().str();
        try
        {
            parse_instructions(instr, line_instr);
        }
        catch (...)
        {
            m_good = 0;
            throw;
        }
    }
    m_parsed = 1;
}

void Parser::parse_instructions(std::queue<const Instruction*>& instr, std::string str)
{
    std::regex instr_pattern("^([^ ]*)( ([^ ]*))*$");
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
    it = std::regex_token_iterator<std::string::iterator>(str.begin(), str.end(), instr_pattern, {3});
    while (it != rend)
    {
        if (it->str().size() > 0)
        {
            std::string str2 = it->str();
            parse_params(params, str2);
        }
        instr.push(m_if.createInstruction(instruction, params));
        ++it;
    }
    params.clear();
}

void Parser::parse_params(std::vector<std::pair<std::string, std::string>> &params, std::string str)
{
    std::smatch param_match;
    std::regex param_pattern("^([^\\(]*)\\((.*)\\)$");
    std::regex n_param_pattern("[-]?[\\d]+");
    std::regex z_param_pattern("[-]?[\\d]+\\.[\\d]+");

    if (std::regex_match(str, param_match, param_pattern))
    {
        if (param_match[1] == "float" || param_match[1] == "double")
        {
            std::string str2 = param_match[2];
            if (std::regex_match(str2, z_param_pattern))
            {
                params.push_back(std::make_pair(param_match[1], param_match[2]));
            }
            else
            {
                throw BrokenFloat();
            }
        }
        else
        {
            std::string str2 = param_match[2];
            if (std::regex_match(str2, n_param_pattern))
            {
                params.push_back(std::make_pair(param_match[1], param_match[2]));
            }
            else
            {
                throw BrokenInteger();
            }
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
