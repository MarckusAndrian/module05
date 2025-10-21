/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:15:10 by kandrian          #+#    #+#             */
/*   Updated: 2025/10/14 14:17:25 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERUCREATIONFORM
#define SHRUBBERUCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
    std::string _target;
    
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
    ~ShrubberyCreationForm();

    void drawAsciiTree() const;
};

#endif

