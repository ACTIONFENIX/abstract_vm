#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Instruction
{
public:
	virtual ~Instruction() = default;

	virtual void exec() = 0;
};

class Push: public Instruction
{

};

#endif //INSTRUCTION_H
