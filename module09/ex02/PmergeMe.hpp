#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
#include <ctime>

#define MAX 2147483647

class PmergeMe
{
private:
    int _ac;
    std::vector<long> _stack;
    std::vector<long> _sortedStack;
    double _time;

    struct Pair {
        int winner;
        int loser;
    };

public:
    PmergeMe();
    PmergeMe(PmergeMe const& other);
    PmergeMe& operator=(PmergeMe const& rhs);
    ~PmergeMe();

    void handleSort(char** const av, int ac);
    std::vector<long> fordJohnsonRecursive(std::vector<long>& data);
    std::vector<long>::iterator findPos(std::vector<long>& stack, long b);
    void setStack(char** const av);
    long checkErr(std::string const& s);
    void printStack(std::vector<long> stack) const;
    void showResult() const;
    void binaryInsertion(std::vector<long>& mainChain, Pair pair);
    std::vector<size_t> insertionSequence(int n);
    std::vector<size_t> generateJacobsthal(int n);

};

#endif