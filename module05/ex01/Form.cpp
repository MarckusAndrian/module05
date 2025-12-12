/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:57:56 by kandrian          #+#    #+#             */
/*   Updated: 2025/12/12 14:40:47 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _signed(0), _name("default_form"), _gradeSign(50), _gradeExec(1)
{
    std::cout << "Default constructor of form called" << std::endl;
}
Form::Form(Form const& other): _signed(0), _name("default_form"), _gradeSign(50), _gradeExec(1)
{
    *this = other;
    std::cout << "Default copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
    {
        _signed = rhs._signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout <<  "Desctructor of form called" << std::endl; 
}

std::string Form::getName(void) const
{
    return this->_name;
}

int Form::getSigned(void) const{
    return this->_signed;
}

int Form::getGradeSign(void) const
{
    return this->_gradeSign;
}

int Form::getGradeExec(void) const
{
    return this->_gradeExec;
}

const char *Form::GradeTooHighException::what() const throw(){
    return ("Too high grade");
}

const char *Form::GradeTooLowException::what() const throw(){
    return ("Too low grade");
}

void Form::beSigned(Bureaucrat const &b)
{
    if (this->_gradeSign >= b.getGrade())
    {
        this->_signed = 1;
    }
    else{
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &o, Form const &f){
    o << "Name: " << f.getName() << std::endl;
    o << "Grade required to sign: " << f.getGradeSign() << std::endl;
    o << "Grade required to execut: " << f.getGradeExec() << std::endl;
    o << "Signed: " << (f.getSigned() == 1 ? "true" :  "false") << std::endl;
    
    return o;
}