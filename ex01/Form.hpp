/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:43:33 by kandrian          #+#    #+#             */
/*   Updated: 2025/09/15 15:34:25 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FROM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    std::string const _name;
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

    std::string getName(void) const;
    int getSigned(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;
    void beSigned(Bureaucrat const &b);
    

};
std::ostream &operator<<(std::ostream &o, Form const &f);

#endif