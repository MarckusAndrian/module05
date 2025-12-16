#ifndef UTILS_TPP
#define UTILS_TPP

#include <iostream>
#include <iomanip>
#include <string>

template <typename T>

void swap(T &a, T &b){
    T temp = a;
    
    a = b;
    b = temp;
}

template <typename T>

T const & max(T const &a, T const &b)
{
    return (a <= b? b : a);
}

template <typename T>

T const & min(T const &a, T const &b)
{
    return (a >= b? b : a);
}

#endif