#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

template<typename T>
void easyfind(T const & a, int const &b)
{
    typename T::const_iterator it = std::find(a.begin(), a.end(), b);
    if (it != a.end())
    {
        std::cout << "Target " << b << " found"  << std::endl;
    }
    else
        throw std::runtime_error("Target not found");
}

#endif