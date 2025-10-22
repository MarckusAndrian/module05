#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "===== SHRUBBERY TEST =====" << std::endl;
    try
    {
        Bureaucrat john(130);
        ShrubberyCreationForm form1("home");

        std::cout << john << std::endl;
        form1.beSigned(john);
        form1.execute(john);

        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== ROBOTOMY TEST =====" << std::endl;
    try
    {
        Bureaucrat alice(40);
        RobotomyRequestForm form2("Marvin");

        std::cout << alice << std::endl;
        form2.beSigned(alice);
        form2.execute(alice);
        form2.execute(alice);

        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== PRESIDENTIAL TEST =====" << std::endl;
    try
    {
        Bureaucrat president(1);
        PresidentialPardonForm form3("Arthur Dent");

        std::cout << president << std::endl;
        form3.beSigned(president);
        form3.execute(president);

        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n===== FAIL TESTS =====" << std::endl;
    try
    {
        Bureaucrat intern(150);
        ShrubberyCreationForm badForm("garden");

        std::cout << intern << std::endl;

        badForm.beSigned(intern);

        badForm.execute(intern);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
