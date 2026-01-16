#ifndef MUTANSTACK
#define MUTANSTACK

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
#include <string>

template <typename T>
class MutanStack: public std::stack<T, std::deque<T>>{
public:
    MutanStack();
    ~MutanStack();

    
};

#endif