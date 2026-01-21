#ifndef BITCOINEXCHANGE_HPP
#define BITCOINECHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <cctype>
#include <sstream>
#include <cstdlib>


class BitcoinExchange
{
private:
    std::map<std::string, std::string> _data;
    std::map<std::string, std::string> _input;
    std::string _inputFileName;

public:
    BitcoinExchange(/* args */);
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);
    ~BitcoinExchange();

    void parseDB();
    void setInputFileName(std::string const &);
    void handleExchange(const char*);
    void lineFormat(std::string line);
    void validDate(std::string date);
    void validValue(std::string);
    void findDateValue(std::string const&, std::string const&);
    std::string trim(std::string const&);
};

#endif