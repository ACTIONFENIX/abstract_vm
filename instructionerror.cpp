#include "instructionerror.h"

int InstructionError::m_line = 0;

InstructionError::InstructionError() noexcept
{
    if (m_line)
    {
        ret += "Line ";
        ret += std::to_string(m_line);
        ret += ": ";
    }
}

void InstructionError::set_line(int line)
{
    m_line = line;
}

const char *InstructionError::what() const noexcept
{
    return ret.c_str();
}

const char *NormalExit::what() const noexcept
{
    return "Exit";
}

const char *NoExit::what() const noexcept
{
    return "No [Exit] instruction founded.";
}

TooManyParams::TooManyParams(const std::string &str) noexcept
{
    ret = InstructionError::what() + std::string("Instruction [") + str + "] provided with too many params.";
}

const char *TooManyParams::what() const noexcept
{
    return ret.c_str();
}

TooLittleParams::TooLittleParams(const std::string &str) noexcept
{
    ret = InstructionError::what() + std::string("Instruction [") + str + "] provided with too little params.";
}

const char *TooLittleParams::what() const noexcept
{
    return ret.c_str();
}

PopEmptyStack::PopEmptyStack() noexcept
{
    ret = std::string(InstructionError::what()) + "Instruction [Pop] tried to remove element from empty stack.";
}

const char *PopEmptyStack::what() const noexcept
{
    return ret.c_str();
}

AssertError::AssertError(const std::string &str, const std::string &top) noexcept
{
    ret = InstructionError::what() + std::string("Instruction [Assert]: assertion failed. Value on top = <") + top + std::string(">, provided value = <") + str + ">.";
}

const char *AssertError::what() const noexcept
{
    return ret.c_str();
}

NotEnoughArgumentsStack::NotEnoughArgumentsStack(const std::string &str) noexcept
{
    ret = InstructionError::what() + std::string("Not enough arguments on stack. ") + str;
}

const char *NotEnoughArgumentsStack::what() const noexcept
{
    return ret.c_str();
}

DivisionByZero::DivisionByZero() noexcept
{
    ret = InstructionError::what() + std::string("Instruction [Div]: division by zero.");
}

const char *DivisionByZero::what() const noexcept
{
    return ret.c_str();
}

ModulusByZero::ModulusByZero() noexcept
{
    ret = InstructionError::what() + std::string("Instruction [Mod]: modulus by zero.");
}

const char *ModulusByZero::what() const noexcept
{
    return ret.c_str();
}

ModulusByFloat::ModulusByFloat() noexcept
{
    ret = InstructionError::what() + std::string("Instruction [Mod]: modulus by floating point number.");
}

const char *ModulusByFloat::what() const noexcept
{
    return ret.c_str();
}

InstructionUnknown::InstructionUnknown() noexcept
{
    ret = InstructionError::what() + std::string("Unknown instruction.");
}

const char *InstructionUnknown::what() const noexcept
{
    return ret.c_str();
}

OperandTypeUnknown::OperandTypeUnknown() noexcept
{
    ret = InstructionError::what() + std::string("Unknown operand type.");
}

const char *OperandTypeUnknown::what() const noexcept
{
    return ret.c_str();
}

ParseError::ParseError(const std::string &str) noexcept
{
    ret = InstructionError::what() + std::string("Parse error. ") + str;
}

const char *ParseError::what() const noexcept
{
    return ret.c_str();
}

BrokenInteger::BrokenInteger() noexcept
{
    ret = InstructionError::what() + std::string("Expected integer value as a parameter.");
}

const char *BrokenInteger::what() const noexcept
{
    return ret.c_str();
}

BrokenFloat::BrokenFloat() noexcept
{
    ret = InstructionError::what() + std::string("Expected floating point value as a parameter.");
}

const char *BrokenFloat::what() const noexcept
{
    return ret.c_str();
}

ValueOverflow::ValueOverflow(const std::string &value, const std::string &type) noexcept
{
    ret = InstructionError::what() + std::string("Value overflow: value ") + value + std::string(" cannot fit inside ") + type + ".";
}

const char *ValueOverflow::what() const noexcept
{
    return ret.c_str();
}

ValueUnderflow::ValueUnderflow(const std::string &value, const std::string &type) noexcept
{
    ret = InstructionError::what() + std::string("Value underflow: value ") + value + std::string(" cannot fit inside ") + type + ".";
}

const char *ValueUnderflow::what() const noexcept
{
    return ret.c_str();
}

PrintError::PrintError() noexcept
{
    ret = std::string(InstructionError::what()) + "Instruction [Print] expected int8 value on stack.";
}

const char *PrintError::what() const noexcept
{
    return ret.c_str();
}
