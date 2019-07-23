TARGET = abstract_vm

CXXFLAGS += -std=c++14 -Wall -Wextra -Werror -Wpedantic

SOURCES += \
    instruction.cpp \
    instructionerror.cpp \
    instructionfactory.cpp \
    main.cpp \
    operand.cpp \
    operandfactory.cpp \
    parser.cpp \
    vm.cpp

OBJS += \
    instruction.o \
    instructionerror.o \
    instructionfactory.o \
    main.o \
    operand.o \
    operandfactory.o \
    parser.o \
    vm.o

HEADERS += \
    instruction.h \
    instructionerror.h \
    instructionfactory.h \
    ioperand.h \
    operand.h \
    operandfactory.h \
    parser.h \
    vm.h

all: $(TARGET)

$(TARGET): $(OBJS)
	clang++ $(OBJS) -o $(TARGET)

%.o: %.cpp
	clang++ $(CXXFLAGS) $< -c

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
