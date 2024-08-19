/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:00:18 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:00:25 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

///Constructos///

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : Name(name), Grade(grade)
{
    if(grade < LowestGrade)
        throw Bureaucrat::GradeTooLowException();
    if(grade > HighestGrade)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat &original)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{

}

Bureaucrat::~Bureaucrat()
{

}

///Class Functions///

const std::string   Bureaucrat::getName(void)
{

}

int                 Bureaucrat::getGrade(void)
{

}

void                Bureaucrat::incrementGrade(void)
{

}

void                Bureaucrat::decrementGrade(void)
{

}

///Exceptions///
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

///Function of insertion overload///
std::ostream &operator<<(std::ostream &COUT, Bureaucrat const &bureaucrat)
{
    //return (COUT << bureaucrat.getName() << ",  bureaucrat grade " << bureaucrat.getGrade() << std::endl);
}
