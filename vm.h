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
    Vm() = default;

    Vm(const std::string& filename);

    ~Vm();

    void run();

private:
    void release_instructions();

private:
    Parser m_parser;
    std::queue<const Instruction*> m_instr;
    std::vector<const IOperand*> m_stack;
};

#endif //VM_H
