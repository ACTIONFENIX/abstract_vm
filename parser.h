#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include "instruction.h"
#include "instructionfactory.h"

class Parser
{
public:
    Parser();

    explicit Parser(const std::string& filename);

    Parser(const Parser&) = default;

    Parser& operator=(const Parser&) = default;

    ~Parser() = default;

    explicit operator bool() const;

private:
    enum class source
    {
        file = 0,
        input
    };

public:
    void open_stream();

    void exec(std::queue<const Instruction*>& instr);

    bool parsed() const;

private:
    void read_file();

    void parse_tokens(std::queue<const Instruction*>& instr);

    void parse_instructions(std::queue<const Instruction *> &instr, std::string str);

    void parse_params(std::vector<std::pair<std::string, std::string> > &params, std::string str);

private:
    const std::string m_filename;
    source m_source; //denotes source - file or standard input from where program is read
    InstructionFactory m_if; //class to create instructions by its name
    std::ifstream file;
    std::istream *in = nullptr; //pointer either to m_filename or to std::cin
    std::string contents; //program buffer
    int m_line = 0; //line to be parsed
    bool m_good = true; //denotes if an error happened while parsing
    bool m_parsed = false; //denotes if parsing is done
};

#endif //PARSE_H
