#include "vm.h"
#include "instructionerror.h"

Vm::Vm()
{
    parse();
}


Vm::Vm(const std::string& filename): m_parser(filename)
{
    parse();
}

Vm::~Vm()
{
    release_instructions();
    release_operands();
}

void Vm::run()
{
    bool normal_exit = 0;

    if (!m_parser)
    {
        std::cerr << "Errors occured during parsing. Stop." << std::endl;
        return;
    }
    while (m_instr.empty() == 0 && normal_exit == 0)
    {
        const Instruction *i = m_instr.front();
        m_instr.pop();
        try
        {
            i->exec(m_stack);
        }
        catch (NormalExit&)
        {
            normal_exit = 1;
        }
        catch (std::exception&)
        {
            release_instructions();
            throw;
        }
        catch (...)
        {
            delete i;
            throw;
        }
        delete i;
    }
    if (normal_exit == 0)
    {
        throw NoExit();
    }
}

void Vm::parse()
{
    while (m_parser.parsed() == 0)
    {
        try
        {
            m_parser.exec(m_instr);
        }
        catch (InstructionError& err)
        {
            std::cerr << "Error: " << err.what() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
        catch (...)
        {
            std::cerr << "Unknown error occured." << std::endl;
            return;
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

void Vm::release_operands()
{
    while (m_stack.empty() == 0)
    {
        delete m_stack.back();
        m_stack.pop_back();
    }
}
