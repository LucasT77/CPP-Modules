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

Bureaucrat::Bureaucrat() : Name("Smallest Cog"), Grade(LOWESTGRADE)
{
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : Name(name), Grade(grade)
{
    std::cout << "Bureaucrat Constructor called" << std::endl;
	if(grade > LOWESTGRADE)
        throw Bureaucrat::GradeTooLowException();
    if(grade < HiGHESTGRADE)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : Name(other.getName()), Grade(other.getGrade())
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
	if (this == &other)
		return *this;
    this->Grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Default Destructor called" << std::endl;
}

///Class Methods///

void	Bureaucrat::setGrade(int grade)
{
	if(grade > LOWESTGRADE)
        throw Bureaucrat::GradeTooLowException();
    if(grade < HiGHESTGRADE)
        throw Bureaucrat::GradeTooHighException();
	else
		Grade = grade;
}

std::string	Bureaucrat::getName(void) const
{
    return (Name);
}

int			Bureaucrat::getGrade(void) const
{
    return (Grade);
}

void		Bureaucrat::incrementGrade(void)
{
    if(Grade - 1 < HiGHESTGRADE)
        throw Bureaucrat::GradeTooHighException();
	else
    	Grade--;
}

void		Bureaucrat::decrementGrade(void)
{
    if(Grade + 1 > LOWESTGRADE)
        throw Bureaucrat::GradeTooLowException();
    else
		Grade++;
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

///Method of insertion overload///
std::ostream &operator<<(std::ostream &COUT, Bureaucrat const &bureaucrat)
{
    return (COUT << bureaucrat.getName() << ",  bureaucrat grade " << bureaucrat.getGrade() << std::endl);
}

//Additional method

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout   << this->Name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
         std::cout   << this->Name << " couldn't sign " 
                    << form.getName()  << " because his grade was too low" << std::endl;
    }
}
