#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

#define RANGE 100

class Span
{
private:
    Span();
    std::vector<int> N;
    unsigned int _i;
public:
    Span(unsigned int n);
    ~Span();

    void addNumber(unsigned int n);
    int shortestSpan() const;
    int longestSpan() const;
    void rangeIterator();
};


#endif