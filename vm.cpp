#include "vm.h"
#include "instructionerror.h"

Vm::Vm(const std::string& filename): m_parser(filename)
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

Vm::~Vm()
{
    release_instructions();
}

void Vm::run()
{
    bool normal_exit = 0;

    if (!m_parser)
    {
        std::cerr << "Errors occured during parsing. Stop." << std::endl;
        return;
    }
    while (m_instr.empty() == 0)
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
    }
    if (normal_exit == 0)
    {
        throw NoExit();
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
