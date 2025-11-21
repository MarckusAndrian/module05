/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:43:33 by kandrian          #+#    #+#             */
/*   Updated: 2025/11/19 15:14:05 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

typedef class AForm AForm;
#include "Bureaucrat.hpp"

class AForm
{
private:
    bool _signed;
    std::string const _name;
    int const _gradeSign;
    int const _gradeExec;

public:
    AForm();
    AForm(std::string name, int const _gradeSign, int const _gradeExce);
    AForm(AForm const &other);
    AForm &operator=(AForm const &rhs);
    ~AForm();

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    class FormNotSignException : public std::exception
    {
        const char *what() const throw();
    };

    std::string getName(void) const;
    int getSigned(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;
    void beSigned(Bureaucrat const &b);

    void checkException(Bureaucrat const &executor) const;
    virtual void execute(Bureaucrat const &executor) const = 0;
};
std::ostream &operator<<(std::ostream &o, AForm const &f);

#endif