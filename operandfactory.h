#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

#include <string>

enum class eOperandType;

class IOperand;

#include <map>

//Factory method for operands
class OperandFactory
{
public:
    OperandFactory() = default;

    OperandFactory(const OperandFactory&) = default;

    OperandFactory& operator=(const OperandFactory&) = default;

    ~OperandFactory() = default;

    const IOperand *createOperand( eOperandType type, std::string const & value ) const;

    const IOperand *createOperand(const std::string& type, std::string const & value ) const;

    eOperandType to_operand_type(const std::string& type) const;

private:
    const IOperand *createInt8( std::string const & value ) const;

    const IOperand *createInt16( std::string const & value ) const;

    const IOperand *createInt32( std::string const & value ) const;

    const IOperand *createFloat( std::string const & value ) const;

    const IOperand *createDouble( std::string const & value ) const;

private:
    static constexpr const IOperand *(OperandFactory::*m_create[])(std::string const & value) const =
    {
        &OperandFactory::createInt8,
        &OperandFactory::createInt16,
        &OperandFactory::createInt32,
        &OperandFactory::createFloat,
        &OperandFactory::createDouble
    };

    static const std::map<std::string, int> m_type;
};

#endif //OPERANDFACTORY_H
