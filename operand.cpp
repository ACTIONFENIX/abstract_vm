#include "operand.h"

Int8::Int8(const std::string& val): OperandBase(std::stoi(val))
{

}

int Int8::getPrecision(void) const
{
    return static_cast<int>(precision::Int8);
}

eOperandType Int8::getType(void) const
{
    return eOperandType::Int8;
}

Int16::Int16(const std::string& val): OperandBase(std::stoi(val))
{

}

int Int16::getPrecision(void) const
{
    return static_cast<int>(precision::Int16);
}

eOperandType Int16::getType(void) const
{
    return eOperandType::Int16;
}

Int32::Int32(const std::string& val): OperandBase(std::stoi(val))
{

}

int Int32::getPrecision(void) const
{
    return static_cast<int>(precision::Int32);
}

eOperandType Int32::getType(void) const
{
    return eOperandType::Int32;
}

Float::Float(const std::string& val): OperandBase(std::stof(val))
{

}

int Float::getPrecision(void) const
{
    return static_cast<int>(precision::Float);
}

eOperandType Float::getType(void) const
{
    return eOperandType::Float;
}

Double::Double(const std::string& val): OperandBase(std::stod(val))
{

}

int Double::getPrecision(void) const
{
    return static_cast<int>(precision::Double);
}

eOperandType Double::getType(void) const
{
    return eOperandType::Double;
}
