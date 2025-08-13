/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kandrian <kandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:40:57 by kandrian          #+#    #+#             */
/*   Updated: 2025/08/13 15:04:39 by kandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a(12);
    Bureaucrat b(150);
    Bureaucrat c(1);

    std::cout << std::endl;
    std::cout << "**Instantiate with a valu out of range" << std::endl;
    try{
        Bureaucrat d(0);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "**Attempt decrement" << std::endl;
    try{
        a.incrementGrade();
        c.decrementGrade();
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        b.decrementGrade();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    return (0);
}