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
#include <deque>

#define MAX 2147483647

class PmergeMe
{
private:
    int _ac;
    std::vector<long> _stack;
    std::vector<long> _sortedStack;
    std::deque<long> _DStack;
    std::deque<long> _DSortedStack;
    double _time;
    double _Dtime;

    struct Pair {
        long winner;
        long loser;
    };

public:
    PmergeMe();
    PmergeMe(PmergeMe const& other);
    PmergeMe& operator=(PmergeMe const& rhs);
    ~PmergeMe();

    void handleSort(char** const av, int ac);
    void setStack(char** const av);
    long checkErr(std::string const& s);
    void showResult() const;

    // ---- VECTOR
    std::vector<size_t> insertionSequence(int n);
    std::vector<size_t> generateJacobsthal(int n);
    void printStack(std::vector<long> stack) const;
    void binaryInsertion(std::vector<long>& mainChain, Pair pair);
    std::vector<long> fordJohnsonRecursive(std::vector<long>& data);

    // ---- DEQUE
    std::deque<size_t> insertionSequenceD(int n);
    std::deque<size_t> generateJacobsthalD(int n);
    void printStack(std::deque<long> stack) const;
    void binaryInsertion(std::deque<long>& mainChain, Pair pair);
    std::deque<long> fordJohnsonRecursive(std::deque<long>& data);

};

#endif