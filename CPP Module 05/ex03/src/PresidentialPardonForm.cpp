/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:04:08 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:04:10 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PresidentialPardonForm.hpp"

////////////////////////////////Constructors & Destructor////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	Target = "Mastermind";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	Target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	this->Target = other.Target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

////////////////////////////////Methods////////////////////////////////////////////////////////////////

void PresidentialPardonForm::execution() const
{
	std::cout << "The target " << Target << " has been pardoned by Zaphold Beeblebrox\n";
}

std::string PresidentialPardonForm::getTarget()
{
	return (Target);
}

void		PresidentialPardonForm::setTarget(std::string target)
{
	Target = target;
}
