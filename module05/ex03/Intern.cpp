#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return *this;
}

Intern::~Intern()
{
}

static AForm *createShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequest(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *creatPresidentialPardon(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {
        "Shrubbery",
        "Robotomy",
        "Presidential"};

    AForm *(*creators[3])(std::string const &target){
        &createShrubbery,
        &createRobotomyRequest,
        &creatPresidentialPardon};

    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern create " << name << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern: form name not found" << std::endl;
    return NULL;
}