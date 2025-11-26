#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(ScalarConvert const &other)
{
    *this = other;
}

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &rhs)
{
    (void)&rhs;
    return *this;
}

ScalarConvert::~ScalarConvert() {};

static bool isNotChar(std::string const &s)
{
    if (s.length() >= 2)
        return false;
}

static bool isNotDigit(std::string const &s)
{
    int i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (; s[i]; i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

static void printCharInt(std::string const &s)
{
    std::cout << "char: ";
    if (isNotChar(s))
        std::cout << "impossible" << std::endl;
    else
    {
        std::cout << s << std::endl;
    }
    std::cout << "int: ";
    if (isNotDigit(s))
        std::cout << "impossible" << std::endl;
    else
    {
        std::cout << s << std::endl;
    }
}

static bool isPseudoLiteral(std::string const &s)
{
    if (s == "nan" || s == "nanf" || s == "-inf" ||
        s == "-inff" || s == "+inff" || s == "+inf")
        return true;
    return false;
}

static void printFloat(std::string const &s)
{
}

void ScalarConvert::convert(std::string const &s)
{
    // chat int float double
    printCharInt(s);
    printFloat(s);
    // printDouble(s);
}