#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>

#define MAX 2147483647 

class PmergeMe
{
private:
    int _ac;
    std::vector<long> _stack;

public:
    PmergeMe();
    PmergeMe(PmergeMe const& other);
    PmergeMe& operator=(PmergeMe const& rhs);
    ~PmergeMe();

    void handleSort(char** const av, int ac);
    std::vector<long> fordJhonson(std::vector<long> stackG);
    void Jacobsthal(std::vector<long>& stackP, std::vector<long>& stackG);
    std::vector<long>::iterator findPos(std::vector<long>& stack, long b);
    void setStack(char** const av);
    long checkErr(std::string const& s);
    void printStack(std::vector<long> stack);
    size_t binarySearch(std::pair<long, long> b) const;
};

#endif