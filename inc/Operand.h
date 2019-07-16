#ifndef OPERAND_H
#define OPERAND_H

#include "IOperand.h"
#include <string>

class Int8: public OperandBase<int8_t>
{
public:
	Int8(const std::string& val);

	int getPrecision(void) const override;

	eOperandType getType(void) const override;
};

#endif //OPERAND_H
