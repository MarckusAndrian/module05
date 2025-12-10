#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    Base *p;

    int randd;
    srand((unsigned)(time(0)));
    randd = ((rand() % 6) + 1) % 3;
    switch (randd)
    {
    case 0:
        p = new A;
        break;
    case 1:
        p = new B;
        break;
    case 2:
        p = new C;
        break;
    default:
        break;
    }
    return p;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "Type of (p) is A*" << std::endl;
    }
    else if ( dynamic_cast<B*>(p))
    {
        std::cout << "Type of (p) is B*" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Type of (p) is C*" << std::endl;
    }
}

void identify(Base& p)
{
    try{
        dynamic_cast<A&>(p);
        std::cout << "Type of (p) is A&" << std::endl;
    }
    catch(std::bad_cast& e)
    {}
    try{
        dynamic_cast<B&>(p);
        std::cout << "Type of (p) is B&" << std::endl;
    }
    catch(std::bad_cast& e)
    {}
    try{
        dynamic_cast<C&>(p);
        std::cout << "Type of (p) is C&" << std::endl;
    }
    catch(std::bad_cast& e)
    {}
}

int main()
{
    Base* p;

    p = generate();
    identify(p);
    identify(*p);
    delete p;
    return (0);
}