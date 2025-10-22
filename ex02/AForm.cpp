/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:57:56 by kandrian          #+#    #+#             */
/*   Updated: 2025/09/19 15:35:46 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _signed(0), _name("default_Aform"), _gradeSign(50), _gradeExec(1)
{
    std::cout << "Default constructor of Aform called" << std::endl;
}

AForm::AForm(int const sign, int const exec) : _signed(0), _name("default_Aform"), _gradeSign(sign), _gradeExec(exec)
{
    std::cout << "AForm's constructor called" << std::endl;
    if (sign < 1 || exec < 1)
        throw AForm::GradeTooHighException();
    else if (sign > 150 || exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) : _signed(0), _name("default_Aform"), _gradeSign(50), _gradeExec(1)
{
    *this = other;
    std::cout << "Default copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "Desctructor of Aform called" << std::endl;
}

std::string AForm::getName(void) const
{
    return this->_name;
}

int AForm::getSigned(void) const
{
    return this->_signed;
}

int AForm::getGradeSign(void) const
{
    return this->_gradeSign;
}

int AForm::getGradeExec(void) const
{
    return this->_gradeExec;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Too high grade!\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Too low grade!\n");
}
const char *AForm::FormNotSignException::what() const throw()
{
    return ("Not signed!\n");
}

void AForm::beSigned(Bureaucrat const &b)
{
    if (this->_gradeSign >= b.getGrade())
    {
        this->_signed = 1;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

void AForm::checkException(Bureaucrat const &executor) const
{
    if (!_signed)
        throw AForm::FormNotSignException();
    if (executor.getGrade() > this->_gradeExec)
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm const &f)
{
    o << "Name: " << f.getName() << std::endl;
    o << "Grade required to sign: " << f.getGradeSign() << std::endl;
    o << "Grade required to execut: " << f.getGradeExec() << std::endl;
    o << "Signed: " << (f.getSigned() == 1 ? "true" : "false") << std::endl;

    return o;
}