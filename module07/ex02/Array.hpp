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
    Array(/* args */): _element(NULL), _n(0){};
    Array(unsigned int n)
    {
        _n = n;
        _element = new T[n];
    };
    Array(Array const &other): _element(NULL), _n(other._n)
    {
        _n = other._n;
        _element = new T[_n];
        for (unsigned int i = 0; i < _n; i++)
            _element[i] = other._element[i];
    }
    Array &operator=(Array const &rhs)
    {
        if (this != &rhs)
        {
            _n = rhs.n;
            if (this->_element)
                delete[] _element;
            _element = (_n > 0)? new T[_n]: NULL;
            for(unsigned int i = 0; i < _n; i++)
            {
                _element[i] = rhs._element[i];
            }
        }
        return *this;
    }
    
    int &operator[](int j)
    {
        unsigned int i = static_cast<unsigned int>(j);
        if (i >= _n)
        {        
            throw std::exception();
        }
        return _element[i];
    }
    int const &operator[](int j) const
    {
        unsigned int i = static_cast<unsigned int>(j);
        if (i >= _n)
        {
            
            throw std::exception();
        }
        return _element[i];
    }

    ~Array(){
        delete[] _element;
    }

};

#endif