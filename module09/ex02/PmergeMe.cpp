#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

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
    _ac =  ac;
    setStack(av);
    fordJhonson(_stack);
}

std::vector<long>::iterator PmergeMe::findPos(std::vector<long>& stack, long b)
{
    std::vector<long>::iterator it = std::lower_bound(stack.begin(), stack.end(), b);

    return it;
}

void PmergeMe::Jacobsthal(std::vector<long>& stackP, std::vector<long>& stackG)
{
    for(size_t i = 0; i < stackP.size(); i++)
    {
        std::vector<long>::iterator cit = findPos(stackG, stackP[i]);
        std::cout << "stack=> \n";
        printStack(stackG);
        std::cout << "found: " << *cit << " to find: " << stackP[i] << std::endl;
        stackG.insert(cit, stackP[i]);
    }
    printStack(stackG);
}


std::vector<long> PmergeMe::fordJhonson(std::vector<long> stack)
{
    std::vector<long> stackG;
    std::vector<long> stackP;

    std::vector<std::pair<long, long>> pairG;
    std::vector<std::pair<long, long>> pairP;
    if (stack.size() >= 2)
    {
        for(size_t i = 0; i < stack.size();)
        {
            int a = stack[i];
            if (i < stack.size() - 1)
            {
                int b = stack[i + 1];
                if (a < b)
                {
                    stackG.push_back(b);
                    stackP.push_back(a);
                    pairG.push_back(std::make_pair<long, long>(a, b));
                }
                else{
                    stackG.push_back(a);
                    stackP.push_back(b);
                    pairG.push_back(std::make_pair<long, long>(b, a));
                }
                i += 2;
            }
            else
            {
                stackP.push_back(a);
                i++;
            }
        }
        std::cout << "\nstackG: \n";
        printStack(stackG);
        std::cout << "\nstackP: \n";
        printStack(stackP);
        stackG = fordJhonson(stackG);


        std::cout <<"\n\n------Jacob------\n\n";
    }
    Jacobsthal(stackP, stackG);
}

size_t PmergeMe::binarySearch() const{
    size_t t;

    std::pair<int, int>(4, 5);
    return t;
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

void PmergeMe::printStack(std::vector<long> stack)
{
    std::vector<long>::iterator it = stack.begin();

    for(; it != stack.end(); it++)
        std::cout << *it << std::endl;
}