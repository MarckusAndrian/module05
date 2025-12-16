#include "iter.hpp"

void func(int& t)
{
    t = 42;
}

int main()
{
    int const n = 5;
    int* tab = new int[n];

    iter(tab, n, func);
    for(int i = 0; i < n; i++)
        std::cout << "tab [" << i <<  "]: " << tab[i] << std::endl;
    delete tab;
    return 0;
}