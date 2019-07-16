#include "../inc/Operand.h"

Int8::Int8(const std::string& val): OperandBase(val)
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
