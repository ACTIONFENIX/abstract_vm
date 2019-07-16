#include "../inc/Vm.h"

Vm::Vm(const std::string& filename): m_parser(filename)
{

}

Vm::~Vm()
{
	release_instructions();
}

void Vm::run()
{
	m_parser.exec();

	while (m_instr.empty() == 0)
	{
		Instruction *i = m_instr.front();
		m_instr.pop();
		try
		{
			i->exec();
		}
		catch (std::exception& e)
		{
			release_instructions();
			throw;
		}
	}
}

void Vm::release_instructions()
{
	while (m_instr.empty() == 0)
	{
		delete m_instr.front();
		m_instr.pop();
	}
}