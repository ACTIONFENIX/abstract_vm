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
    source m_source;
    InstructionFactory m_if;
    std::ifstream file;
    std::istream *in = nullptr;
    std::string contents;
    int m_line = 0;
    bool m_good = true;
    bool m_parsed = false;
};

#endif //PARSE_H
