#include "operandfactory.h"
#include "operand.h"
#include "instructionerror.h"

OperandFactory::OperandFactory()
{
    m_type.insert(std::make_pair("int8", 0));
    m_type.insert(std::make_pair("int16", 1));
    m_type.insert(std::make_pair("int32", 2));
    m_type.insert(std::make_pair("float", 3));
    m_type.insert(std::make_pair("double", 4));
}

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
    if (static_cast<unsigned long>(type) >= sizeof(m_create) / sizeof(m_create[0]))
    {
        throw OperandTypeUnknown();
    }
    return ((*this).*m_create[static_cast<int>(type)])(value);
}

IOperand const * OperandFactory::createOperand(const std::string& type, std::string const & value ) const
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

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
    return new Int8(value);
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
    return new Int16(value);
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
    return new Int32(value);
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
    return new Float(value);
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
    return new Double(value);
}
