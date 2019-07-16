#include "../inc/OperandFactory.h"

IOperand const * (OperandFactory::*OperandFactory::m_create[])(std::string const & value) const =
{
	&OperandFactory::createInt8,
	&OperandFactory::createInt16,
	&OperandFactory::createInt32,
	&OperandFactory::createFloat,
	&OperandFactory::createDouble
};

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	return m_create[static_cast<int>(type)](value);
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
