#ifndef INTERN
#define INTERN

#include "Bureaucrat.hpp"

class Intern
{
private:
public:
    Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &rhs);
    ~Intern();

    AForm *makeForm(std::string name, std::string target);
};


#endif