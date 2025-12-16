#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void iter(T* tab, int const n,  void func(T&)){
    for(int i = 0; i < n; i++)
    {
        func(tab[i]);
    }
}

#endif