cmake_minimum_required(VERSION 3.13)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 17)

add_executable(abstract_vm main.cpp src/Parse.cpp inc/Parse.h inc/IOperand.h inc/Instruction.h inc/Vm.h src/Vm.cpp inc/OperandFactory.h src/OperandFactory.cpp inc/Operand.h src/Operand.cpp)