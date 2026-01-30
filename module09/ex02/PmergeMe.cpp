#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
    if (this != &rhs)
    {
        _stack = rhs._stack;
    }
    return *this;
}

void PmergeMe::handleSort(char** const av, int ac)
{

    _ac = ac;
    setStack(av);
    std::vector<long> stackG = _stack;
    clock_t start = clock();
    _sortedStack = fordJohnsonRecursive(stackG);
    clock_t end = clock();
    _time = double(end - start) / 1000;
    showResult();
}

std::vector<long>::iterator PmergeMe::findPos(std::vector<long>& stack, long b)
{
    std::vector<long>::iterator it = std::lower_bound(stack.begin(), stack.end(), b);

    return it;
}
std::vector<size_t> PmergeMe::generateJacobsthal(int n) {
    std::vector<size_t> j;
    j.push_back(0);
    j.push_back(1);

    int next = 0;
    while (next < n) {
        next = j.back() + 2 * j[j.size() - 2];
        j.push_back(next);
    }
    return j;
}

std::vector<size_t> PmergeMe::insertionSequence(int n) {
    std::vector<size_t> j = generateJacobsthal(n);
    std::vector<size_t> sequence;

    for (size_t i = 1; i < j.size(); ++i) {
        int start = j[i];
        int end = j[i - 1];
        int current = (start > n) ? n : start;

        while (current > end) {
            sequence.push_back(current);
            current--;
        }
    }
    return sequence;
}


/*-----------------------------------------------------------------------*/


void PmergeMe::binaryInsertion(std::vector<long>& mainChain, Pair pair) {
    std::vector<long>::iterator limit = std::find(mainChain.begin(), mainChain.end(), pair.winner);
    std::vector<long>::iterator it = std::lower_bound(mainChain.begin(), limit, pair.loser);
    mainChain.insert(it, pair.loser);
}

std::vector<long> PmergeMe::fordJohnsonRecursive(std::vector<long>& data) {
    size_t n = data.size();
    if (n <= 1) return data;

    std::vector<Pair> pairs;
    std::vector<long> winners;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? data.back() : 0;

    for (size_t i = 0; i < n - 1; i += 2) {
        Pair p;
        if (data[i] > data[i + 1]) {
            p.winner = data[i];
            p.loser = data[i + 1];
        }
        else {
            p.winner = data[i + 1];
            p.loser = data[i];
        }
        pairs.push_back(p);
        winners.push_back(p.winner);
    }

    std::vector<long> mainChain = fordJohnsonRecursive(winners);

    // 3. Insertion du A1
    int firstWinner = mainChain[0];
    std::vector<Pair> newPair;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].winner == firstWinner) {
            mainChain.insert(mainChain.begin(), pairs[i].loser);
        }
        else
        {
            newPair.push_back(pairs[i]);
        }
    }
    if (newPair.size() >= 1)
    {
        std::vector<size_t> seq = insertionSequence(newPair.size());
        for (size_t i = 0; i < seq.size(); i++)
        {
            size_t index = seq[i] - 1;
            binaryInsertion(mainChain, newPair[index]);
        }
    }

    // // 5. Si on avait un élément impair, on l'insère à la fin
    if (hasStraggler) {
        std::vector<long>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    return mainChain;
}


void PmergeMe::setStack(char** const av)
{
    for (int i = 1; i < _ac; i++)
    {
        _stack.push_back(checkErr(av[i]));
    }
}

long PmergeMe::checkErr(std::string const& s)
{
    long b;
    if (s.find_first_not_of("0123456789+") != std::string::npos)
        throw std::runtime_error("error: invalid number!");
    if (s.find_first_of("+") != s.find_last_of("+"))
        throw std::runtime_error("error: double sign +!");
    b = std::strtol(s.c_str(), NULL, 10);
    if (b > MAX)
        throw std::runtime_error("error: out of INT_MAX!");
    if (b < 0)
        throw std::runtime_error("error: Negative number!");
    return b;
}

void PmergeMe::printStack(std::vector<long> stack) const
{
    std::vector<long>::iterator it = stack.begin();

    for (; it != stack.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::showResult() const
{
    std::cout << "Before: ";
    printStack(_stack);
    std::cout << "After: ";
    printStack(_sortedStack);
    std::cout << "Time to process a range of 3000 elements with std::vector: " << _time << std::endl;
}