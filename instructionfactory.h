#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include "instruction.h"
#include <string>
#include <map>
#include <vector>

enum class InstructionType
{
    push = 0,
    pop,
    dump,
    assert,
    add,
    sub,
    mul,
    div,
    mod,
    print,
    exit
};

class InstructionFactory
{
public:
    InstructionFactory();

    Instruction *createInstruction(InstructionType type, const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>()) const;

    Instruction *createInstruction(const std::string& type, const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>()) const;

private:
    Instruction *createPush(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createPop(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createDump(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createAssert(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createAdd(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createSub(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createMul(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createDiv(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createMod(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createPrint(const std::vector<std::pair<std::string, std::string>>& params) const;

    Instruction *createExit(const std::vector<std::pair<std::string, std::string>>& params) const;

private:
    static constexpr Instruction *(InstructionFactory::*m_create[])(const std::vector<std::pair<std::string, std::string>>& params) const =
    {
        &InstructionFactory::createPush,
        &InstructionFactory::createPop,
        &InstructionFactory::createDump,
        &InstructionFactory::createAssert,
        &InstructionFactory::createAdd,
        &InstructionFactory::createSub,
        &InstructionFactory::createMul,
        &InstructionFactory::createDiv,
        &InstructionFactory::createMod,
        &InstructionFactory::createPrint,
        &InstructionFactory::createExit
    };

    std::map<std::string, int> m_type;
};

#endif //INSTRUCTIONFACTORY_H
