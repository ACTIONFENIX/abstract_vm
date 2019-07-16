#ifndef IOPERAND_H
#define IOPERAND_H

#include "OperandFactory.h"
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
	OperandFactory m_factory;
};

template<typename T>
OperandBase<T>::OperandBase(T val): m_val(val)
{

}

template<typename T>
IOperand const *OperandBase<T>::operator+(const IOperand &src) const
{
	return m_factory.createOperand(getType(), m_val + std::to_string(dynamic_cast<OperandBase&>(src).val));
}

template<typename T>
IOperand const *OperandBase<T>::operator-(const IOperand &src) const
{
	return m_factory.createOperand(getType(), m_val - std::to_string(dynamic_cast<OperandBase&>(src).val));
}

template<typename T>
IOperand const *OperandBase<T>::operator*(const IOperand &src) const
{
	return m_factory.createOperand(getType(), m_val * std::to_string(dynamic_cast<OperandBase&>(src).val));
}

template<typename T>
IOperand const *OperandBase<T>::operator/(const IOperand &src) const
{
	return m_factory.createOperand(getType(), m_val / std::to_string(dynamic_cast<OperandBase&>(src).val));
}

template<typename T>
IOperand const *OperandBase<T>::operator%(const IOperand &src) const
{
	return m_factory.createOperand(getType(), m_val % std::to_string(dynamic_cast<OperandBase&>(src).val));
}

template<typename T>
std::string const &OperandBase<T>::toString(void) const
{
	return std::to_string(m_val);
}

#endif //IOPERAND_H
