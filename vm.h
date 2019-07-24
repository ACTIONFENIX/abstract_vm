#ifndef VM_H
#define VM_H

#include <string>
#include <queue>
#include <vector>
#include "parser.h"
#include "instruction.h"
#include "ioperand.h"

class Vm
{
public:
    Vm();

    Vm(const std::string& filename);

    Vm(const Vm&) = default;

    Vm& operator=(const Vm&) = default;

    ~Vm();

    void run();

private:
    void parse();

    void release_instructions();

    void release_operands();

private:
    Parser m_parser;
    std::queue<const Instruction*> m_instr;
    std::vector<const IOperand*> m_stack;
};

#endif //VM_H
