#ifndef INSTRUCTIONERROR_H
#define INSTRUCTIONERROR_H

#include <exception>
#include <string>

//basic class to allmost all exceptions in abstract_vm
class InstructionError: public std::exception
{
public:
    InstructionError() noexcept;

    InstructionError(const InstructionError&) = default;

    InstructionError& operator=(const InstructionError&) = default;

    virtual ~InstructionError() = default;

    virtual const char *what() const noexcept = 0;

    static void set_line(int line);

protected:
    static int m_line;
    std::string ret;
};

//raises if exit instruction is executed
class NormalExit: public InstructionError
{
public:
    NormalExit() noexcept = default;

    const char *what() const noexcept;

    ~NormalExit() = default;
};

//raises if no exit instruction was executed
class NoExit: public InstructionError
{
public:
    NoExit() noexcept = default;

    const char *what() const noexcept;

    ~NoExit() = default;
};

//raises if instruction got too many parameters
class TooManyParams: public InstructionError
{
public:
    TooManyParams(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~TooManyParams() = default;
};

//raises if instruction got too little parameters
class TooLittleParams: public InstructionError
{
public:
    TooLittleParams(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~TooLittleParams() = default;
};

//raises if Pop instruction executed on empty stack
class PopEmptyStack: public InstructionError
{
public:
    PopEmptyStack() noexcept;

    const char *what() const noexcept;

    ~PopEmptyStack() = default;
};

//raises while Assert instruction executes if value on top of the stack is not the same as in the parameter
class AssertError: public InstructionError
{
public:
    AssertError(const std::string& str, const std::string& top) noexcept;

    const char *what() const noexcept;

    ~AssertError() = default;
};

//raises if there is no at least 2 operands in stack while any binary instruction, like Add, is executed
class NotEnoughArgumentsStack: public InstructionError
{
public:
    NotEnoughArgumentsStack(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~NotEnoughArgumentsStack() = default;
};

//raises if Div instruction divides by 0
class DivisionByZero: public InstructionError
{
public:
    DivisionByZero() noexcept;

    const char *what() const noexcept;

    ~DivisionByZero() = default;
};

//raises if Mod instruction gets remainder by 0
class ModulusByZero: public InstructionError
{
public:
    ModulusByZero() noexcept;

    const char *what() const noexcept;

    ~ModulusByZero() = default;
};

//raises if 1 of Mod instruction operands is floating value
class ModulusByFloat: public InstructionError
{
public:
    ModulusByFloat() noexcept;

    const char *what() const noexcept;

    ~ModulusByFloat() = default;
};

//raises if instruction to be created is unknown
class InstructionUnknown: public InstructionError
{
public:
    InstructionUnknown() noexcept;

    const char *what() const noexcept;

    ~InstructionUnknown() = default;
};

//raises if operand type to be created is unknown
class OperandTypeUnknown: public InstructionError
{
public:
    OperandTypeUnknown() noexcept;

    const char *what() const noexcept;

    ~OperandTypeUnknown() = default;
};

//raises if any unspecified here error occured while parsing program
class ParseError: public InstructionError
{
public:
    ParseError(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~ParseError() = default;
};

//raises if integer operand value is wrong
class BrokenInteger: public InstructionError
{
public:
    BrokenInteger() noexcept;

    const char *what() const noexcept;

    ~BrokenInteger() = default;
};

//raises if floating point operand value is wrong
class BrokenFloat: public InstructionError
{
public:
    BrokenFloat() noexcept;

    const char *what() const noexcept;

    ~BrokenFloat() = default;
};

//raises if while creating operand the value passed to it can't fit in its type
class ValueOverflow: public InstructionError
{
public:
    ValueOverflow(const std::string& value, const std::string& type) noexcept;

    const char *what() const noexcept;

    ~ValueOverflow() = default;
};

//raises if while creating operand the value passed to it can't fit in its type
class ValueUnderflow: public InstructionError
{
public:
    ValueUnderflow(const std::string& value, const std::string& type) noexcept;

    const char *what() const noexcept;

    ~ValueUnderflow() = default;
};

//raises if while executing Print instruction type of value on the top is not int8
class PrintError: public InstructionError
{
public:
    PrintError() noexcept;

    const char *what() const noexcept;

    ~PrintError() = default;
};

#endif // INSTRUCTIONERROR_H
