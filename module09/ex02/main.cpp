#include "PmergeMe.hpp"

// int rec(int b)
// {
//     if (b > 2)
//     {
//         b -= 2;
//         std::cout << "f p:" << b << std::endl;
//         rec(b);
//         std::cout << "s p" << b << std::endl;
//         return b;
//     }
//     return b;
// }

int main(int ac, char** av)
{
    PmergeMe p;
    if (ac < 2)
    {
        std::cerr << "error: Need atlest 2 nomber" << std::endl;
        return 1;
    }
    try {
        p.handleSort(av, ac);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}