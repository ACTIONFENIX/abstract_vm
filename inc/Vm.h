#ifndef VM_H
#define VM_H

#include <string>
#include <queue>
#include <vector>
#include "Parse.h"
#include "Instruction.h"
#include "IOperand.h"

class Vm
{
public:
	Vm() = default;

	Vm(const std::string& filename);

	~Vm();

	void run();

private:
	void release_instructions();

private:
	Parser m_parser;
	std::queue<Instruction*> m_instr;
	std::vector<IOperand*> m_ops;
};

#endif //VM_H
