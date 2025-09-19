/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:57:35 by kandrian          #+#    #+#             */
/*   Updated: 2025/09/19 15:16:21 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

typedef class Bureaucrat Bureaucrat;

#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;
    
public:
    Bureaucrat();
    Bureaucrat(int newGrade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &rhs);
    ~Bureaucrat();

    class GradeTooHighException: public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        const char* what() const throw();
    };

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &f);
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const & b);

#endif