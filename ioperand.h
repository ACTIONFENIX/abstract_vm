#ifndef IOPERAND_H
#define IOPERAND_H

#include "operandfactory.h"
#include "instructionerror.h"
#include <string>

enum class eOperandType
{
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
};

enum class precision
{
    Int8 = 0,
    Int16 = 1,
    Int32 = 2,
    Float = 3,
    Double = 4
};

class IOperand
{
public:
    virtual int getPrecision(void) const = 0;

    virtual eOperandType getType(void) const = 0;

    virtual IOperand const *operator+(const IOperand &src) const = 0;

    virtual IOperand const *operator-(const IOperand &src) const = 0;

    virtual IOperand const *operator*(const IOperand &src) const = 0;

    virtual IOperand const *operator/(const IOperand &src) const = 0;

    virtual IOperand const *operator%(const IOperand &src) const = 0;

    virtual std::string const &toString(void) const = 0;

    virtual ~IOperand(void) = default;
};

template<typename T>
class OperandBase: public IOperand
{
public:
    OperandBase(T val);

    IOperand const *operator+(const IOperand &src) const override;

    IOperand const *operator-(const IOperand &src) const override;

    IOperand const *operator*(const IOperand &src) const override;

    IOperand const *operator/(const IOperand &src) const override;

    IOperand const *operator%(const IOperand &src) const override;

    std::string const &toString(void) const override;

private:
    T m_val;
    const std::string m_str;
    OperandFactory m_factory;
};

template<typename T>
OperandBase<T>::OperandBase(T val): m_val(val), m_str(std::to_string(m_val))
{

}

template<typename T>
IOperand const *OperandBase<T>::operator+(const IOperand &src) const
{
    return m_factory.createOperand(std::max(getType(), src.getType()), std::to_string(m_val + std::stod(src.toString())));
}

template<typename T>
IOperand const *OperandBase<T>::operator-(const IOperand &src) const
{
    return m_factory.createOperand(std::max(getType(), src.getType()), std::to_string(m_val - std::stod(src.toString())));
}

template<typename T>
IOperand const *OperandBase<T>::operator*(const IOperand &src) const
{
    return m_factory.createOperand(std::max(getType(), src.getType()), std::to_string(m_val * std::stod(src.toString())));
}

template<typename T>
IOperand const *OperandBase<T>::operator/(const IOperand &src) const
{
    if (src.toString() != "0")
    {
        return m_factory.createOperand(std::max(getType(), src.getType()), std::to_string(m_val / std::stod(src.toString())));
    }
    else
    {
        throw DivisionByZero();
    }
}

template<typename T>
IOperand const *OperandBase<T>::operator%(const IOperand &src) const
{
    if (src.toString() != "0")
    {
        return m_factory.createOperand(std::max(getType(), src.getType()), std::to_string(m_val % std::stoi(src.toString())));
    }
    else
    {
        throw ModulusByZero();
    }
}

template<>
inline IOperand const *OperandBase<float>::operator%(const IOperand &) const
{
    throw ModulusByFloat();
}

template<>
inline IOperand const *OperandBase<double>::operator%(const IOperand &) const
{
    throw ModulusByFloat();
}

template<typename T>
std::string const &OperandBase<T>::toString(void) const
{
    return m_str;
}

#endif //IOPERAND_H
