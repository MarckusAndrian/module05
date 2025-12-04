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

float parseFloat(std::string const &s)
{
    double d = std::strtod(s.c_str(), NULL);

    return static_cast<float>(d);
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
    double d = std::strtod(s.c_str(), NULL);
    if (d < 0 || d > 255)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if (c < 32 && c >= 0 || c == 127)
    {
        std::cout << "non displayble" << std::endl;
        return;
    }
    else
    {
        std::cout << c << std::endl;
    }
}

static void printInt(std::string const &s)
{
    std::cout << "int: ";
    if (isNotDigit(s) || (INT_MAX < parseInt(s) || INT_MIN > parseInt(s)))
        std::cout << "impossible" << std::endl;
    else
    {
        std::cout << parseInt(s) << std::endl;
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
    float f = parseFloat(s);
    std::cout << "float: ";
    if (isPseudoLiteral(s))
        return;
    if (isNotDigit(s))
        return;
    if (f - static_cast<int>(f) == 0)
        std::cout << f << ".0f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
}

void ScalarConvert::convert(std::string const &s)
{
    // chat int float double

    printChar(s);
    printInt(s);
    printFloat(s);
    // printDouble(s);
}
