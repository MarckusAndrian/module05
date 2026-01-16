#include "Array.hpp"


int main()
{
    try{
        Array<int> a(-3);
        a[1] = 5;
        std::cout << a[2] << std::endl;
    }
    catch(std::exception const &e)
    {
        (void) e;
        std::cerr << "Out of bounds!" << std::endl;
    }
    return 0;
}