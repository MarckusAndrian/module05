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

// --- parsing
static bool isNotDigit(std::string const &s)
{
    int i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (; s[i]; i++)
    {
        if (!isdigit(s[i]) && s[i] != 'f' && s[i] != '.')
            return true;
    }
    return false;
}

long parseInt(std::string const &s)
{
    long res;

    if (isNotDigit(s))
        return 0;
    res = std::strtol(s.c_str(), NULL, 10);
    return res;
}

float parseDouble(std::string const &s)
{
    double d = strtod(s.c_str(), NULL);

    return (d);
}

// --- print
static bool isNotChar(std::string const &s)
{
    if (s.length() >= 2)
    {
        if (!isNotDigit(s) && (s.find('f') == std::string::npos))
            return false;
        return true;
    }
    return false;
}

static void printChar(std::string const &s)
{
    std::cout << "char: ";
    if (isNotChar(s))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    double d = strtod(s.c_str(), NULL);
    if (d < 0 || d > 255)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if ((c < 32 && c >= 0) || c == 127)
    {
        std::cout << "non displayble" << std::endl;
        return;
    }
    else
    {
        std::cout << "'" << c  << "'" << std::endl;
    }
}

static void printInt(std::string const &s)
{
    std::cout << "int: ";
    if (isNotDigit(s) || (INT_MAX < parseInt(s) || INT_MIN > parseInt(s)))
        std::cout << "impossible" << std::endl;
    else
        std::cout << parseInt(s) << std::endl;
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
    res = strtol(s.c_str(), NULL, 10);
    if (res > INT_MAX || res < INT_MIN)
        return false;
    return true;
}
static bool isFloat(std::string const &s)
{
    return true;
}

static void printFloat(std::string const &s)
{
    float f = static_cast<float>(parseDouble(s));
    if (isPseudoLiteral(s))
        return;
    std::cout << "float: ";
    if (isNotDigit(s))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (f - static_cast<int>(f) == 0)
        std::cout << f << ".0f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
}

static void printDouble(std::string const &s)
{
    double d = parseDouble(s);
    if (isPseudoLiteral(s))
        return;
    std::cout << "double: ";
    if (isNotDigit(s))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (d - static_cast<int>(d) == 0)
        std::cout << d << ".0" << std::endl;
    else
        std::cout << d << std::endl;
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
    else if (s[0] == '+')
    {

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
        return;
    }
    printChar(s);
    printInt(s);
    printFloat(s);
    printDouble(s);
}
