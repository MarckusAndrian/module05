/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:43:33 by kandrian          #+#    #+#             */
/*   Updated: 2025/08/13 16:06:33 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FROM_HPP

#include <iostream>
#include <string>

class Form
{
private:
    std::string _name;
    bool _signed;
    int const _gradeSign;
    int const _gradeExec;

public:
    Form();
    Form(Form const &other);
    Form &operator=(Form const &rhs);
    ~Form();

    class GradeTooHighException: public std::exception
    {
        const char *what() const throw();
    };
    
    class GradeTooLowException: public std::exception
    {
        const char *what() const throw();
    };
};


#endif