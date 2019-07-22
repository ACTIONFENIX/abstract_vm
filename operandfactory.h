#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

#include <string>

enum class eOperandType;

class IOperand;

#include <map>

class OperandFactory
{
public:
    OperandFactory();

    IOperand const * createOperand( eOperandType type, std::string const & value ) const;

    IOperand const * createOperand(const std::string& type, std::string const & value ) const;

    eOperandType to_operand_type(const std::string& type) const;

private:
    IOperand const * createInt8( std::string const & value ) const;

    IOperand const * createInt16( std::string const & value ) const;

    IOperand const * createInt32( std::string const & value ) const;

    IOperand const * createFloat( std::string const & value ) const;

    IOperand const * createDouble( std::string const & value ) const;

private:
    static constexpr const IOperand * (OperandFactory::*m_create[])(std::string const & value) const =
    {
        &OperandFactory::createInt8,
        &OperandFactory::createInt16,
        &OperandFactory::createInt32,
        &OperandFactory::createFloat,
        &OperandFactory::createDouble
    };

    std::map<std::string, int> m_type;
};

#endif //OPERANDFACTORY_H
