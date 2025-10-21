/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:18:02 by kandrian          #+#    #+#             */
/*   Updated: 2025/10/14 14:35:11 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(145, 137), _target("tree")
{
    std::cout << "Default constructor of shrubbery called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(145, 137), _target(target)
{
    std::cout << "Constructor of shrubbery called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm(145, 137), _target("tree")
{
    *this = other;
    std::cout << "Copy constructor of shrubbery is called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        _target = rhs._target;

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor of shrubbery called" << std::endl;
}

void ShrubberyCreationForm::drawAsciiTree() const{
    std::ofstream f1;
    std::string   fname;
    
    fname = _target + "_shrubbery";
    f1.open(fname.c_str());
    if (!f1.is_open())
        return ;

    f1 << "          &&& &&  & &&" << std::endl;
    f1 << "      && &\/&\|& ()|/ @, &&" << std::endl;
    f1 << "      &\/(/&/&||/& /_/)_&/_&" << std::endl;
    f1 << "   &() &\/&|()|/&\/ '%'' & ()" << std::endl;
    f1 << "  &_\_&&_\ |& |&&/&__%_/_& &&" << std::endl;
    f1 << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    f1 << " ()&_---()&\&\|&&-&&--%---()~" << std::endl;
    f1 << "     &&     \|||" << std::endl;
    f1 << "             |||" << std::endl;
    f1 << "             |||" << std::endl;
    f1 << "             |||" << std::endl;
    f1 << "       , -=-~  .-^- _" << std::endl;
    
    f1.close();
}