#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{

    if (ac != 2)
    {
        std::cout << "Bad argument!" <<std::endl;
        return (1);
    }   
    try{
        BitcoinExchange b;
        b.handleExchange(av[1]);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

// ----------------- //
    return (0);
}