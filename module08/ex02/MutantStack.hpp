#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:
    MutantStack(){};
    MutantStack(MutantStack const &other):std::stack<T, Container>(other){}
    MutantStack &operator=(MutantStack const &rhs)
    {
        if (this != &rhs)
        {
            std::stack<T, Container>::operator=(rhs);
        }
        return *this;
    }
    ~MutantStack(){};

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;


    iterator begin(){
        return this->c.begin();
    };

    iterator end(){
        return this->c.end();
    }

    const_iterator cbegin() const{
        return this->c.cbegin();
    }

    const_iterator cend() const{
        return this->c.cend();
    }

    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }

    const_reverse_iterator crbegin() const
    {
        return this->c.crbegin();
    }

    const_reverse_iterator crend() const
    {
        return this->c.crend();
    }
};

#endif