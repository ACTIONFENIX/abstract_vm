#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include "ioperand.h"
#include "operandfactory.h"

class Instruction
{
public:
    virtual ~Instruction() = default;

    virtual void exec(std::vector<const IOperand*>& stack) const = 0;

    virtual size_t nparams() const = 0;
};

class Push: public Instruction
{
public:
    Push(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;

public:
    std::string param_type;
    std::string param;
    OperandFactory m_of;
};

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

class Assert: public Instruction
{
public:
    Assert(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;

public:
    std::string param_type;
    std::string param;
    OperandFactory m_of;
};

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

class Print: public Instruction
{
public:
    Print(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;

private:
    OperandFactory m_of;
};

class Exit: public Instruction
{
public:
    Exit(const std::vector<std::pair<std::string, std::string>>& params = std::vector<std::pair<std::string, std::string>>());

    void exec(std::vector<const IOperand*>& stack) const override;

    size_t nparams() const override;
};

#endif //INSTRUCTION_H
