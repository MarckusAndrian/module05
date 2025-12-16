#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
private:
    T* _element; 
    unsigned int _n;
    /* data */
public:
    Array<T>(/* args */){
        _element = NULL;
    };
    Array<T>(unsigned int n): 
    {
        _n = n;
        _element = new T[n];
    };
    Array<T>(Array const &other){
        *this = other;
    }
    Array &operator=(Array const &rhs)
    {
        if (this->_element)
            delete _element;
        _element = new T[_n];
        for
    }

};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &a)
{
    return o;
}

#endif;