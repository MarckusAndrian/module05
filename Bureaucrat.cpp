/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:01:23 by kandrian          #+#    #+#             */
/*   Updated: 2025/08/12 01:29:32 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat"), _grade(100)
{
    std::cout << "Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(int newGrade): _name("Bureaucrat"), _grade(newGrade)
{
    std::cout << "Constructor called" << std::endl;
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
}

void Bureaucrat::decrementGrade()
{
    this->_grade++;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return;
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return;
};

std::string Bureaucrat::getName() const 
{
    return this->_name;
}
