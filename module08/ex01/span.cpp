#include "span.hpp"

Span::Span(unsigned int n):N(n), _i(0){
};
Span::~Span(){};

void Span::addNumber(unsigned int n)
{
    std::vector<int>::iterator it = std::find(N.begin(), N.end(), n);
    if (it != N.end())
        throw std::runtime_error("Number already existed");
    if (_i < n)
        N[_i++] = n;
    else
        N.push_back(n);
}

int Span::shortestSpan() const {
    if (N.size() < 2)
        throw std::runtime_error("Need two or more number!");
    std::vector<int>::const_iterator it = N.begin();
    int shortest = *it;
    int max;
    int min;
    for(;it != N.end(); it++)
    {
        for(std::vector<int>::const_iterator i = N.begin(); i != N.end(); i++)
        {
            if (*it == *i)
                break ;
            max = *it > *i ? *it : *i;
            min = *it < *i ? *it : *i;
            shortest = (shortest < (max - min))? shortest: (max - min);
        }
    }
    return shortest;
}

int Span::longestSpan() const{
        if (N.size() <  2)
        throw std::runtime_error("Need two or more number!");
    std::vector<int>::const_iterator it = N.begin();
    int max = *(it);
    int min = *it;
    for(;it != N.end(); it++)
    {
        max = std::max(max, *it);
        min = std::min(min, *it);
    }
    return max - min;
}

void Span::rangeIterator()
{
    std::srand(std::time(0));
    for(int i = 0; i < RANGE; i++)
    {
        int n = std::rand();
        while(std::find(N.begin(), N.end(), n) != N.end())
        {
            n = rand();
        }
        addNumber(n);
    }
}