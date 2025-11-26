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
    std::cout << "char: " << s << std::endl;
    std::cout << "int: " << s << std::endl;
}

static bool isPseudoLiteral(std::string const &s)
{
    if (s == "nan" || s == "nanf" || s == "-inf" ||
        s == "-inff" || s == "+inff" || s == "+inf")
        return true;
    return false;
}

static bool parseInt(std::string const &s, long &res)
{
    if (isNotDigit(s))
        return false;
    res = std::strtol(s.c_str(), NULL, 10);
    if (res > INT32_MAX || res < INT32_MIN )
        return false;
    return true;
}
static bool isFloat(std::string const &s)
{
    return true;
}

static void printFloat(std::string const &s)
{
}
static void printPseudoLiteral(std::string const &s)
{
    if (s == "nan" || "nanf")
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
    }
    else if (s[0] == '+'){

        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "+inff" << std::endl;
        std::cout << "double: " << "+inf" << std::endl;
    }
    else
    {
            std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
    }
}

void ScalarConvert::convert(std::string const &s)
{
    if (s.empty())
    {
        std::cout << "Conversion impossible" << std::endl;
    }
    if (isPseudoLiteral(s))
    {
        printPseudoLiteral(s);
    }
    else if (!(isNotChar(s) && !isNotDigit(s)))
        printCharInt(s);
    else if (isFloat(s)) {
        printFloat(s);
    }
    // chat int float double
    printFloat(s);
    // printDouble(s);
}