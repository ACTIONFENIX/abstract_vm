#ifndef INSTRUCTIONERROR_H
#define INSTRUCTIONERROR_H

#include <exception>
#include <string>

class InstructionError: public std::exception
{
public:
    InstructionError() noexcept;

    virtual ~InstructionError() = default;

    virtual const char *what() const noexcept = 0;

    static void set_line(int line);

protected:
    static int m_line;
    std::string ret;
};

class NormalExit: public InstructionError
{
public:
    NormalExit() noexcept = default;

    const char *what() const noexcept;

    ~NormalExit() = default;
};

class NoExit: public InstructionError
{
public:
    NoExit() noexcept = default;

    const char *what() const noexcept;

    ~NoExit() = default;
};

class TooManyParams: public InstructionError
{
public:
    TooManyParams(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~TooManyParams() = default;
};

class TooLittleParams: public InstructionError
{
public:
    TooLittleParams(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~TooLittleParams() = default;
};

class PopEmptyStack: public InstructionError
{
public:
    PopEmptyStack() noexcept;

    const char *what() const noexcept;

    ~PopEmptyStack() = default;
};

class AssertError: public InstructionError
{
public:
    AssertError(const std::string& str, const std::string& top) noexcept;

    const char *what() const noexcept;

    ~AssertError() = default;
};

class NotEnoughArgumentsStack: public InstructionError
{
public:
    NotEnoughArgumentsStack(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~NotEnoughArgumentsStack() = default;
};

class DivisionByZero: public InstructionError
{
public:
    DivisionByZero() noexcept;

    const char *what() const noexcept;

    ~DivisionByZero() = default;
};

class ModulusByZero: public InstructionError
{
public:
    ModulusByZero() noexcept;

    const char *what() const noexcept;

    ~ModulusByZero() = default;
};

class ModulusByFloat: public InstructionError
{
public:
    ModulusByFloat() noexcept;

    const char *what() const noexcept;

    ~ModulusByFloat() = default;
};

class InstructionUnknown: public InstructionError
{
public:
    InstructionUnknown() noexcept;

    const char *what() const noexcept;

    ~InstructionUnknown() = default;
};

class OperandTypeUnknown: public InstructionError
{
public:
    OperandTypeUnknown() noexcept;

    const char *what() const noexcept;

    ~OperandTypeUnknown() = default;
};

class ParseError: public InstructionError
{
public:
    ParseError(const std::string& str) noexcept;

    const char *what() const noexcept;

    ~ParseError() = default;
};

class BrokenInteger: public InstructionError
{
public:
    BrokenInteger() noexcept;

    const char *what() const noexcept;

    ~BrokenInteger() = default;
};

class BrokenFloat: public InstructionError
{
public:
    BrokenFloat() noexcept;

    const char *what() const noexcept;

    ~BrokenFloat() = default;
};

//TO USE
class ValueOverflow: public InstructionError
{
public:
    ValueOverflow(const std::string& value, const std::string& type) noexcept;

    const char *what() const noexcept;

    ~ValueOverflow() = default;
};

//TO USE
class ValueUnderflow: public InstructionError
{
public:
    ValueUnderflow(const std::string& value, const std::string& type) noexcept;

    const char *what() const noexcept;

    ~ValueUnderflow() = default;
};

#endif // INSTRUCTIONERROR_H
