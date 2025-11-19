#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern &Intern::operator=(Intern const &rhs)
{
    return *this;
}

Intern::~Intern()
{}

AForm *Intern::makeForm(std::string name, std::string target)
{
}