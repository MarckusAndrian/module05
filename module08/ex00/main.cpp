#include "easyfind.hpp"

int main()
{
    {

        try{
            std::vector<int> v(5, 0);
            easyfind(v, 9);
        }
        catch(std::exception const &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        try{
            std::list<int> l(5, 0);
            easyfind(l, 0);
        }
        catch(std::exception const &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}