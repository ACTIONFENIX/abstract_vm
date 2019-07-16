#include "../inc/Parse.h"

Parser::Parser(): m_source(source::input), m_state(state::S)
{

}

Parser::Parser(const std::string& filename): m_filename(filename), m_source(source::file), m_state(state::S)
{

}

void Parser::exec()
{

}