#include "operand.h"

Int8::Int8(const std::string& val)
{
    int n;
    try
    {
        n = std::stoi(val);
    }
    catch (std::out_of_range)
    {
        if (val[0] == '-')
        {
            throw ValueUnderflow(val, "int8");
        }
        else
        {
            throw ValueOverflow(val, "int8");
        }
    }
    catch (...)
    {
        throw;
    }
    if (n < std::numeric_limits<int8_t>::min())
    {
        throw ValueUnderflow(val, "int8");
    }
    if (n > std::numeric_limits<int8_t>::max())
    {
        throw ValueOverflow(val, "int8");
    }
    m_val = static_cast<int8_t>(n);
    m_str = std::to_string(m_val);
}

int Int8::getPrecision(void) const
{
    return static_cast<int>(precision::Int8);
}

eOperandType Int8::getType(void) const
{
    return eOperandType::Int8;
}

Int16::Int16(const std::string& val)
{
    int n;
    try
    {
        n = std::stoi(val);
    }
    catch (std::out_of_range)
    {
        if (val[0] == '-')
        {
            throw ValueUnderflow(val, "int16");
        }
        else
        {
            throw ValueOverflow(val, "int16");
        }
    }
    catch (...)
    {
        throw;
    }
    if (n < std::numeric_limits<int16_t>::min())
    {
        throw ValueUnderflow(val, "int16");
    }
    if (n > std::numeric_limits<int16_t>::max())
    {
        throw ValueOverflow(val, "int16");
    }
    m_val = static_cast<int16_t>(n);
    m_str = std::to_string(m_val);
}

int Int16::getPrecision(void) const
{
    return static_cast<int>(precision::Int16);
}

eOperandType Int16::getType(void) const
{
    return eOperandType::Int16;
}

Int32::Int32(const std::string& val)
{
    try
    {
        m_val = std::stoi(val);
    }
    catch (std::out_of_range)
    {
        if (val[0] == '-')
        {
            throw ValueUnderflow(val, "int32");
        }
        else
        {
            throw ValueOverflow(val, "int32");
        }
    }
    catch (...)
    {
        throw;
    }
    m_str = std::to_string(m_val);
}

int Int32::getPrecision(void) const
{
    return static_cast<int>(precision::Int32);
}

eOperandType Int32::getType(void) const
{
    return eOperandType::Int32;
}

Float::Float(const std::string& val)
{
    try
    {
        m_val = std::stof(val);
    }
    catch (std::out_of_range)
    {
        if (val[0] == '-')
        {
            throw ValueUnderflow(val, "float");
        }
        else
        {
            throw ValueOverflow(val, "float");
        }
    }
    catch (...)
    {
        throw;
    }
    m_str = std::to_string(m_val);
}

int Float::getPrecision(void) const
{
    return static_cast<int>(precision::Float);
}

eOperandType Float::getType(void) const
{
    return eOperandType::Float;
}

Double::Double(const std::string& val)
{
    try
    {
        m_val = std::stod(val);
    }
    catch (std::out_of_range)
    {
        if (val[0] == '-')
        {
            throw ValueUnderflow(val, "double");
        }
        else
        {
            throw ValueOverflow(val, "double");
        }
    }
    catch (...)
    {
        throw;
    }
    m_str = std::to_string(m_val);
}

int Double::getPrecision(void) const
{
    return static_cast<int>(precision::Double);
}

eOperandType Double::getType(void) const
{
    return eOperandType::Double;
}
