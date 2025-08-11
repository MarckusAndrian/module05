/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:57:35 by kandrian          #+#    #+#             */
/*   Updated: 2025/08/08 15:12:41 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Bureaucrat
{
private:
    std::string const _name;
    int _grade;   
public:
    Bureaucrat(/* args */);
    ~Bureaucrat();
};
