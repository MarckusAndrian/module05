#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(72, 45), _target("Roboto")
{
    std::cout << "RobotomyRequest default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(72, 45), _target(target)
{
    std::cout << "RobotomyRequest constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(72, 45), _target("Roboto")
{
    *this = other;
    std::cout << "RobotomyRequest copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequest destructor called" << std::endl;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkException(executor);

    std::cout << _target << "PSZZZZzzzzz ... drilling noises" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << "Roboto failed" << std::endl;
}