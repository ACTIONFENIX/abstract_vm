#ifndef OPERAND_H
#define OPERAND_H

#include "ioperand.h"
#include <string>

class Int8: public OperandBase<int8_t>
{
public:
    explicit Int8(const std::string& val);

    int getPrecision(void) const override;

    eOperandType getType(void) const override;
};

class Int16: public OperandBase<int16_t>
{
public:
    explicit Int16(const std::string& val);

    int getPrecision(void) const override;

    eOperandType getType(void) const override;
};

class Int32: public OperandBase<int32_t>
{
public:
    explicit Int32(const std::string& val);

    int getPrecision(void) const override;

    eOperandType getType(void) const override;
};

class Float: public OperandBase<float>
{
public:
    explicit Float(const std::string& val);

    int getPrecision(void) const override;

    eOperandType getType(void) const override;
};

class Double: public OperandBase<double>
{
public:
    explicit Double(const std::string& val);

    int getPrecision(void) const override;

    eOperandType getType(void) const override;
};

#endif //OPERAND_H
