#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include "ioperand.h"
#include "operandfactory.h"

class Instruction
{
public:
    virtual ~Instruction() = default;

    //execute command
    virtual void exec(std::vector<const IOperand*>& stack) const = 0;

    //return command's number of parameters
    virtual size_t nparams() const = 0;
};

//push single operand to stack
class Push: public Instruction
{
public:
    Push() = delete;
    
    Push(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());
    
    Push(const Push&) = delete;
    
    Push& operator=(const Push&) = delete;

    ~Push() override = default;

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;

public:
    std::string param_type;
    std::string param;
    OperandFactory m_of;
};


//pop from stack
class Pop: public Instruction
{
public:
    Pop(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

class Dump: public Instruction
{
public:
    Dump(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

//raise an error if operand's value and type doesn't match to the specified in the single parameter
class Assert: public Instruction
{
public:
    Assert() = delete;

    Assert(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    Assert(const Assert&) = delete;

    Assert& operator=(const Assert&) = delete;

    ~Assert() override = default;

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;

public:
    std::string param_type;
    std::string param;
    OperandFactory m_of;
};

//gets 2 operands from stack, adds them and pushes its sum
class Add: public Instruction
{
public:
    Add(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

class Sub: public Instruction
{
public:
    Sub(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

class Mul: public Instruction
{
public:
    Mul(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

class Div: public Instruction
{
public:
    Div(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

class Mod: public Instruction
{
public:
    Mod(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

//print value on top of the stack if its parameter is int8, otherwise raise an error
class Print: public Instruction
{
public:
    Print() = delete;

    Print(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    Print(const Print&) = delete;

    Print& operator=(const Print&) = delete;

    ~Print() override = default;

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;

private:
    OperandFactory m_of;
};

//instruction that stops the execution. must appear at least once in the code, otherwise raise an error
class Exit: public Instruction
{
public:
    Exit(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

//change sign of the value on the top of the stack
class Neg: public Instruction
{
public:
    Neg(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

//the same as push, but with any number of parameters to push
class Pushl: public Instruction
{
public:
    Pushl() = delete;

    Pushl(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    Pushl(const Pushl&) = delete;

    Pushl& operator=(const Pushl&) = delete;

    ~Pushl() override = default;

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;

public:
    const std::vector<std::pair<std::string, std::string>> m_params;
    OperandFactory m_of;
};

#endif //INSTRUCTION_H
