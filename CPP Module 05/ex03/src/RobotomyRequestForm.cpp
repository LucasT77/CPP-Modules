/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:03:53 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:03:54 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RobotomyRequestForm.hpp"

////////////////////////////////Constructors & Destructor////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	Target = "RoboCop";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	Target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	this->Target = other.Target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

////////////////////////////////Methods////////////////////////////////////////////////////////////////

void RobotomyRequestForm::execution() const
{
	std::cout	<< "huuuuuuuuuummmmmmmmmmmm...\n"
				<< "zzzzuuuuuuuuuummmmmmuuuummuuuummmmmm...\n"
				<< "huuuuuuuuuummwwwwzzzzmmmuuuuuuummmmmmm...\n";
	
	srand(time(0));
	if (rand() % 2 == 1)
		std::cout << "The target " << Target << " has been robotomized.\n";
	else
		std::cout << "The robotomy has failed.\n";
}

std::string RobotomyRequestForm::getTarget()
{
	return (Target);
}

void		RobotomyRequestForm::setTarget(std::string target)
{
	Target = target;
}