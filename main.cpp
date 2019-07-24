#include <iostream>
#include "vm.h"

int main(int argc, char *argv[])
{
    if (argc == 1) //if no parameters passed, read from standard input
    {
        try
        {
            Vm vm;

            vm.run();
        }
        catch (std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Unknown error occured." << std::endl;
        }
    }
    else if (argc == 2) //otherwise read from file
    {
        try
        {
            Vm vm(argv[1]);

            vm.run();
        }
        catch (std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Unknown error occured." << std::endl;
        }
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " [filename]" << std::endl;
    }
    return 0;
}
