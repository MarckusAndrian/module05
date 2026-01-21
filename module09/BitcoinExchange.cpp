#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other){
    *this  = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs){
    (void)rhs;
    // if (this != &rhs)
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::trim(std::string const &str) {
    if (str.empty()) return str;

    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}   

void BitcoinExchange::handleExchange(const char *fileName)
{
    std::ifstream file(fileName, std::ifstream::in);

    if (!file.is_open())
        throw std::runtime_error("Open input file failed!");
    parseDB();
    std::string line;
    std::getline(file, line);
    if (line.empty())
        throw std::runtime_error("Empty input file!");
    if (line.compare("date | value") != 0)
        throw std::runtime_error("Line format invalid!");
    line.clear();
    while(std::getline(file, line))
    {
        try{
            lineFormat(line);
            int pos = line.find_first_of("|");
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            validDate(trim(key));
            validValue(trim(value));
            findDateValue(trim(key), trim(value));
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        line.clear();
    }
    file.close();
}

void BitcoinExchange::validValue(std::string value)
{
    double d = std::strtod(value.c_str(), NULL);

    if (d < 0)
    {
        std::cout << value << " => ";
        throw std::runtime_error("Not a positive number!");
    }
    if (d > 1000)
    {
        std::cout << value << " => ";
        throw std::runtime_error("Too large number!");
    }
}

void BitcoinExchange::findDateValue(std::string const& key, std::string const &value)
{
    std::map<std::string, std::string>::iterator it, itlow;
    std::string tkey;
    double tvalue;

    it = _data.find(key);
    if (it == _data.end())
    {
        itlow = _data.lower_bound(key);
        --itlow;
        tkey = itlow->first;
    }
    else
    {
        tkey = it->first;
    }
    tvalue = std::strtod(value.c_str(), NULL) * std::strtod(_data[tkey].c_str(), NULL);
    std::cout << key << " => " << value << " = " << tvalue << std::endl;
}

void BitcoinExchange::validDate(std::string date)
{
    struct tm tm;

    std::memset(&tm, 0, sizeof(tm));
    tm.tm_isdst = -1;

    char *s = strptime(date.c_str(), "%Y-%m-%d", &tm);
    if (s == NULL || *s != '\0')
    {
        std::cout << date << " => ";
        throw std::runtime_error("Invalid Date");
    }

    int m = tm.tm_mon;
    int y = tm.tm_year;
    int d = tm.tm_mday;
    if(mktime(&tm) == -1)
        throw std::runtime_error("mktime error!");
    if (y != tm.tm_year || m != tm.tm_mon || d != tm.tm_mday)
    {
        std::cout << date << " => ";
        throw std::runtime_error("Invalid date!");
    }

}

void BitcoinExchange::parseDB(){
    std::ifstream file("data.csv", std::ifstream::in);

    if (!file.is_open())
    {
        throw std::runtime_error("Open DB file failed") ;
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::string key;
        std::string value;
        key = line.substr(0, line.find(","));
        value = line.substr(line.find(",") + 1);
        _data.insert(std::make_pair(key, value));
        line.clear();
        key.clear();
        value.clear();
    }
    file.close();
}

void BitcoinExchange::lineFormat(std::string line) {
    size_t pos = line.find_first_of("|");
    if (pos == std::string::npos)
    {
        std::cout << line << " => ";
        throw std::runtime_error("Format invalid");
    }
    std::string key = line.substr(0, pos);
    std::string value = line.substr(pos + 1);

    if (key.find_first_not_of("0123456789- ") != std::string::npos)
    {
        std::cout << line << " => ";
        throw std::runtime_error("Char invalid!");
    }

    if (trim(value).find_first_not_of("+") != std::string::npos && trim(value).find_last_not_of("+") != 0)
    {
        std::cout << line << " => ";
        throw std::runtime_error("Char invalid!");
    }
    if (value.find_first_not_of("0123456789- +.") != std::string::npos)
    {
        std::cout << line << " => ";
        throw std::runtime_error("Char invalid!");
    }
   
    if(value.find_last_of(' ') != 0)
    {
        std::cout << value << " => ";
        throw std::runtime_error("Format invalid");
    }
    
    if(key.find_first_of(' ') != key.size() - 1)
    {
        std::cout << key << " => ";
        throw std::runtime_error("Format invalid");
    }
    
}

void BitcoinExchange::setInputFileName(std::string const &fileName)
{
    _inputFileName = fileName;
}
