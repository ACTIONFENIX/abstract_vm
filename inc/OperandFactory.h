#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

#include <string>
#include "Operand.h"

class OperandFactory
{
public:
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:
	IOperand const * createInt8( std::string const & value ) const;

	IOperand const * createInt16( std::string const & value ) const;

	IOperand const * createInt32( std::string const & value ) const;

	IOperand const * createFloat( std::string const & value ) const;

	IOperand const * createDouble( std::string const & value ) const;

private:
	static IOperand const * (OperandFactory::*m_create[])(std::string const & value) const;
};

#endif //OPERANDFACTORY_H
