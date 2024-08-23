/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:01:22 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:01:24 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"

///Constructos///

AForm::AForm() : Name("Square"), Grade_toSign(120), Grade_toExecute(90)
{
	std::cout << "AForm Default Constructor called" << std::endl;
	Is_signed = false;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : Name(name), Grade_toSign(gradeToSign), Grade_toExecute(gradeToExecute)
{
	std::cout << "AForm Constructor called" << std::endl;
	if(gradeToSign > LOWESTGRADE || gradeToExecute > LOWESTGRADE)
        throw Bureaucrat::GradeTooLowException();
    if(gradeToSign < HiGHESTGRADE || gradeToExecute < HiGHESTGRADE)
        throw Bureaucrat::GradeTooHighException();
}

AForm::AForm(AForm &other) : Name(other.getName()), Grade_toSign(other.getGradeToSign()), Grade_toExecute(other.getGradeToExecute())
{
	std::cout << "AForm copy constructor called" << std::endl;
	if(Grade_toSign > LOWESTGRADE || Grade_toExecute > LOWESTGRADE)
        throw Bureaucrat::GradeTooLowException();
    if(Grade_toSign < HiGHESTGRADE || Grade_toExecute < HiGHESTGRADE)
        throw Bureaucrat::GradeTooHighException();
	else
		*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm copy assignment constructor called" << std::endl;
	if (this == &other)
		return (*this);
	else
		this->Is_signed = other.getIsSigned();
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm Default Destructor called" << std::endl;
}

///Class Methods///

std::string	AForm::getName(void) const
{
	return Name;
}

bool		AForm::getIsSigned(void) const
{
	return Is_signed;
}

int			AForm::getGradeToSign(void) const
{
	return Grade_toSign;
}

int			AForm::getGradeToExecute(void) const
{
	return Grade_toExecute;
}

void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->Grade_toSign)
		Is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

///Exceptions///

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed";
}

///Method of insertion overload///

std::ostream &operator<<(std::ostream &COUT, AForm const &Aform)
{
    if (Aform.getIsSigned() == true)
		return (COUT << Aform.getName() << " is signed"  << std::endl);
	else
		return (COUT << Aform.getName() << " is NOT signed"  << std::endl);
}

//New Method
void AForm::execute(Bureaucrat const & executor) const 
{
	if (executor.getGrade() > Grade_toExecute)
		throw AForm::GradeTooLowException();
	if (Is_signed == false)
		throw AForm::FormNotSignedException(); 
	else
		this->execution();
}
