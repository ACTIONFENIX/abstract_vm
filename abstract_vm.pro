TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        instruction.cpp \
        instructionerror.cpp \
        instructionfactory.cpp \
        main.cpp \
        operand.cpp \
        operandfactory.cpp \
        parser.cpp \
        vm.cpp

HEADERS += \
    instruction.h \
    instructionerror.h \
    instructionfactory.h \
    ioperand.h \
    operand.h \
    operandfactory.h \
    parser.h \
    vm.h

DISTFILES += \
    file.txt \
    file2.txt
