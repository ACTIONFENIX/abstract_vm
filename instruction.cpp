#include "instruction.h"
#include "instructionerror.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

Push::Push(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Push");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Push");
    }
    param_type = params.begin()->first;
    param = params.begin()->second;
}

void Push::exec(std::vector<const IOperand*>& stack) const
{
    stack.push_back(m_of.createOperand(param_type, param));
}

size_t Push::nparams() const
{
    return 1;
}

Pop::Pop(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Pop");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Pop");
    }
}

void Pop::exec(std::vector<const IOperand*>& stack) const
{
    if (stack.size() > 0)
    {
        delete stack.back();
        stack.pop_back();
    }
    else
    {
        throw PopEmptyStack();
    }
}

size_t Pop::nparams() const
{
    return 0;
}

Dump::Dump(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Dump");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Dump");
    }
}

void Dump::exec(std::vector<const IOperand*>& stack) const
{
    for (auto i = stack.rbegin(); i != stack.rend(); ++i)
    {
        std::cout << (*i)->toString() << std::endl;
    }
}

size_t Dump::nparams() const
{
    return 0;
}

Assert::Assert(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Assert");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Assert");
    }
    param_type = params.begin()->first;
    param = params.begin()->second;
}

void Assert::exec(std::vector<const IOperand*>& stack) const
{
    static constexpr double eps = 1e-10;
    if (stack.empty())
    {
        throw AssertError(param, "no value");
    }
    if (stack.back()->getType() != m_of.to_operand_type(param_type) || abs(std::stod(stack.back()->toString()) - std::stod(param)) > eps)
    {
        throw AssertError(param, stack.back()->toString());
    }
}

size_t Assert::nparams() const
{
    return 1;
}

Add::Add(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Add");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Add");
    }
}

void Add::exec(std::vector<const IOperand*>& stack) const
{
    if (stack.size() >= 2)
    {
        const IOperand *res = *stack.back() + *stack[stack.size() - 2];
        delete stack.back();
        stack.pop_back();
        delete stack.back();
        stack.pop_back();
        stack.push_back(res);
    }
    else
    {
        throw NotEnoughArgumentsStack(std::string("Binary instruction [Add] expected 2, but got only ") + std::to_string(stack.size()) + ".");
    }
}

size_t Add::nparams() const
{
    return 0;
}

Sub::Sub(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Sub");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Sub");
    }
}

void Sub::exec(std::vector<const IOperand*>& stack) const
{
    if (stack.size() >= 2)
    {
        const IOperand *res = *stack[stack.size() - 2] - *stack.back();
        delete stack.back();
        stack.pop_back();
        delete stack.back();
        stack.pop_back();
        stack.push_back(res);
    }
    else
    {
        throw NotEnoughArgumentsStack(std::string("Binary instruction [Sub] expected 2, but got only ") + std::to_string(stack.size()) + ".");
    }
}

size_t Sub::nparams() const
{
    return 0;
}

Mul::Mul(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Mul");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Mul");
    }
}

void Mul::exec(std::vector<const IOperand*>& stack) const
{
    if (stack.size() >= 2)
    {
        const IOperand *res = *stack.back() * *stack[stack.size() - 2];
        delete stack.back();
        stack.pop_back();
        delete stack.back();
        stack.pop_back();
        stack.push_back(res);
    }
    else
    {
        throw NotEnoughArgumentsStack(std::string("Binary instruction [Mul] expected 2, but got only ") + std::to_string(stack.size()) + ".");
    }
}

size_t Mul::nparams() const
{
    return 0;
}

Div::Div(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Div");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Div");
    }
}

void Div::exec(std::vector<const IOperand*>& stack) const
{
    if (stack.size() >= 2)
    {
        const IOperand *res = *stack[stack.size() - 2] / *stack.back();
        delete stack.back();
        stack.pop_back();
        delete stack.back();
        stack.pop_back();
        stack.push_back(res);
    }
    else
    {
        throw NotEnoughArgumentsStack(std::string("Binary instruction [Div] expected 2, but got only ") + std::to_string(stack.size()) + ".");
    }
}

size_t Div::nparams() const
{
    return 0;
}

Mod::Mod(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Mod");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Mod");
    }
}

void Mod::exec(std::vector<const IOperand*>& stack) const
{
    if (stack.size() >= 2)
    {
        const IOperand *res = *stack.back() % *stack[stack.size() - 2];
        delete stack.back();
        stack.pop_back();
        delete stack.back();
        stack.pop_back();
        stack.push_back(res);
    }
    else
    {
        throw NotEnoughArgumentsStack(std::string("Binary instruction [Mod] expected 2, but got only ") + std::to_string(stack.size()) + ".");
    }
}

size_t Mod::nparams() const
{
    return 0;
}

Print::Print(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Print");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Print");
    }
}

void Print::exec(std::vector<const IOperand*>& stack) const
{
    if (stack.empty())
    {
        throw NotEnoughArgumentsStack(std::string("Unary instruction [Print] expected 1, but got only 0."));
    }
    if (stack.back()->getType() != m_of.to_operand_type("int8"))
    {
        throw PrintError();
    }
    else
    {
        std::cout << static_cast<char>(std::stoi(stack.back()->toString())) << std::endl;
    }
}

size_t Print::nparams() const
{
    return 0;
}

Exit::Exit(const std::vector<std::pair<std::string, std::string>>& params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Exit");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Exit");
    }
}

void Exit::exec(std::vector<const IOperand*>&) const
{
    throw NormalExit();
}

size_t Exit::nparams() const
{
    return 0;
}

Neg::Neg(const std::vector<std::pair<std::string, std::string> > &params)
{
    if (params.size() < nparams())
    {
        throw TooLittleParams("Neg");
    }
    if (params.size() > nparams())
    {
        throw TooManyParams("Neg");
    }
}

void Neg::exec(std::vector<const IOperand *> &stack) const
{
    if (stack.size() > 0)
    {
        const IOperand *res = -*stack.back();
        delete stack.back();
        stack.pop_back();
        stack.push_back(res);
    }
    else
    {
        throw NotEnoughArgumentsStack(std::string("Unary instruction [Neg] expected 1, but got only 0."));
    }
}

size_t Neg::nparams() const
{
    return 0;
}

Pushl::Pushl(const std::vector<std::pair<std::string, std::string> > &params): m_params(params)
{

}

void Pushl::exec(std::vector<const IOperand *> &stack) const
{
    for (auto i: m_params)
    {
        stack.push_back(m_of.createOperand(i.first, i.second));
    }
}

size_t Pushl::nparams() const
{
    return 0;
}
