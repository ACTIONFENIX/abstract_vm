#include "instructionfactory.h"

InstructionFactory::InstructionFactory()
{
    m_type.insert(std::make_pair("push", 0));
    m_type.insert(std::make_pair("pop", 1));
    m_type.insert(std::make_pair("dump", 2));
    m_type.insert(std::make_pair("assert", 3));
    m_type.insert(std::make_pair("add", 4));
    m_type.insert(std::make_pair("sub", 5));
    m_type.insert(std::make_pair("mul", 6));
    m_type.insert(std::make_pair("div", 7));
    m_type.insert(std::make_pair("mod", 8));
    m_type.insert(std::make_pair("print", 9));
    m_type.insert(std::make_pair("exit", 10));
}

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
