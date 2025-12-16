#include "Array.hpp"


int main()
{
    Array<int> *a = new  Array<int>();

    try{
        std::cout << *a << std::endl;

    }
    catch(std::exception const &e)
    {
        std::cerr << "Out of bounds!" << std::endl;
    }
    return 0;
}