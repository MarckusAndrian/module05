#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>

void iter(T* tab, int const n,  U func){
    for(int i = 0; i < n; i++)
    {
        func(tab[i]);
    }
}

#endif