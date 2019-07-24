#include "instructionfactory.h"

constexpr Instruction *(InstructionFactory::*InstructionFactory::m_create[])(const std::vector<std::pair<std::string, std::string>>& params) const;

const std::map<std::string, int> InstructionFactory::m_type =
{
    {"push", 0},
    {"pop", 1},
    {"dump", 2},
    {"assert", 3},
    {"add", 4},
    {"sub", 5},
    {"mul", 6},
    {"div", 7},
    {"mod", 8},
    {"print", 9},
    {"exit", 10},
    {"neg", 11},
    {"pushl", 12}
};

Instruction *InstructionFactory::createInstruction(InstructionType type, const std::vector<std::pair<std::string, std::string>>& params) const
{
    if (static_cast<unsigned long>(type) >= sizeof(m_create) / sizeof(m_create[0]))
    {
        throw InstructionUnknown();
    }
    return ((*this).*m_create[static_cast<int>(type)])(params);
}

Instruction *InstructionFactory::createInstruction(const std::string& type, const std::vector<std::pair<std::string, std::string>>& params) const
{
    InstructionType t;
    if (m_type.find(type) != m_type.end())
    {
        t = static_cast<InstructionType>(m_type.at(type));
    }
    else
    {
        t = static_cast<InstructionType>(sizeof(m_create) / sizeof(m_create[0]));
    }
    return createInstruction(t, params);
}

Instruction *InstructionFactory::createPush(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Push(params);
}

Instruction *InstructionFactory::createPop(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Pop(params);
}

Instruction *InstructionFactory::createDump(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Dump(params);
}

Instruction *InstructionFactory::createAssert(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Assert(params);
}

Instruction *InstructionFactory::createAdd(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Add(params);
}

Instruction *InstructionFactory::createSub(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Sub(params);
}

Instruction *InstructionFactory::createMul(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Mul(params);
}

Instruction *InstructionFactory::createDiv(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Div(params);
}

Instruction *InstructionFactory::createMod(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Mod(params);
}

Instruction *InstructionFactory::createPrint(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Print(params);
}

Instruction *InstructionFactory::createExit(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Exit(params);
}

Instruction *InstructionFactory::createNeg(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Neg(params);
}

Instruction *InstructionFactory::createPushl(const std::vector<std::pair<std::string, std::string>>& params) const
{
    return new Pushl(params);
}
