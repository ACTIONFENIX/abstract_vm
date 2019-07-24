#include "operandfactory.h"
#include "operand.h"
#include "instructionerror.h"

constexpr const IOperand *(OperandFactory::*OperandFactory::m_create[])(std::string const & value) const;

const std::map<std::string, int> OperandFactory::m_type =
{
    {"int8", 0},
    {"int16", 1},
    {"int32", 2},
    {"float", 3},
    {"double", 4}
};

const IOperand *OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
    if (static_cast<unsigned long>(type) >= sizeof(m_create) / sizeof(m_create[0]))
    {
        throw OperandTypeUnknown();
    }
    return ((*this).*m_create[static_cast<int>(type)])(value);
}

const IOperand *OperandFactory::createOperand(const std::string& type, std::string const & value ) const
{
    eOperandType t;
    if (m_type.find(type) != m_type.end())
    {
        t = static_cast<eOperandType>(m_type.at(type));
    }
    else
    {
        t = static_cast<eOperandType>(sizeof(m_create) / sizeof(m_create[0]));
    }
    return createOperand(t, value);
}

eOperandType OperandFactory::to_operand_type(const std::string &type) const
{
    return static_cast<eOperandType>(m_type.at(type));
}

const IOperand *OperandFactory::createInt8( std::string const & value ) const
{
    return new Int8(value);
}

const IOperand *OperandFactory::createInt16( std::string const & value ) const
{
    return new Int16(value);
}

const IOperand *OperandFactory::createInt32( std::string const & value ) const
{
    return new Int32(value);
}

const IOperand *OperandFactory::createFloat( std::string const & value ) const
{
    return new Float(value);
}

const IOperand *OperandFactory::createDouble( std::string const & value ) const
{
    return new Double(value);
}
