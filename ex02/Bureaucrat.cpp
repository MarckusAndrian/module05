/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:23 by kandrian          #+#    #+#             */
/*   Updated: 2025/09/19 16:10:54 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat"), _grade(100)
{
    std::cout << "Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(int newGrade): _name("Bureaucrat")
{
    std::cout << "Constructor called" << std::endl;
    if (newGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = newGrade;
};

Bureaucrat::Bureaucrat(Bureaucrat const & other): _name("Bureaucrat"), _grade(100)
{
    std::cout << "Default copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
    {
        this->_grade = rhs.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Descructor called" << std::endl;
}

void Bureaucrat::incrementGrade()
{
    this->_grade--;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    this->_grade++;
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Highest grade attempt");
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Lowest grade attempt");
};

std::string Bureaucrat::getName() const 
{
    return this->_name;
}

void Bureaucrat::signForm(AForm &f)
{
    try{
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign " << f.getName();
        std::cout << " because " << "the grade is not high enough" << std::endl;
    }
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}
