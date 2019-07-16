#ifndef PARSE_H
#define PARSE_H

#include <string>

class Parser
{
public:
	Parser();

	Parser(const std::string& filename);

private:
	enum class state
	{
		S = 0,
		ERR_SEP_MAIN,
		S_MAIN,
		SEP,
		INSTR,
		INSTR_PUSH,
		INSTR_POP,
		INSTR_DUMP,
		INSTR_ASSERT,
		INSTR_ADD,
		INSTR_SUB,
		INSTR_MUL,
		INSTR_DIV,
		INSTR_MOD,
		INSTR_PRINT,
		INSTR_EXIT,
		ERR_INSTR_UNKNOWN,
		VALUE,
		VALUE_INT8,
		VALUE_INT16,
		VALUE_INT32,
		VALUE_FLOAT,
		VALUE_DOUBLE,
		N,
		Z,
		ERR_WRONG_N,
		ERR_WRONG_Z
	};

	enum class source
	{
		file = 0,
		input
	};

public:
	void exec();

private:
	const std::string m_filename;
	source m_source;
	state m_state;
};

#endif //PARSE_H
