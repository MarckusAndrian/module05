#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default_form", 72, 45), _target("Roboto")
{
    std::cout << "RobotomyRequest default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Default_form", 72, 45), _target(target)
{
    std::cout << "RobotomyRequest constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm("Default_form", 72, 45), _target("Roboto")
{
    *this = other;
    std::cout << "RobotomyRequest copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "RobotomyRequest destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    checkException(executor);

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}