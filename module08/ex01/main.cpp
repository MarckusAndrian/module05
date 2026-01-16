#include "span.hpp"

int main()
{
    {
        try{
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(std::exception const &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n ------------------- Range test --------------- " << std::endl;
        try{
            Span sp = Span(5);
            sp.rangeIterator();
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(std::exception const &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}