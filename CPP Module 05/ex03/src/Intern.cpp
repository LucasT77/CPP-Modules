/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:04:53 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:04:55 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern &other) {(void)other;}
Intern &Intern::operator=(const Intern &other) 
{
	(void)other;
	return *this;
}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string	upper_name;
	std::string	formTypes[3] = {"SHRUBBERY", "ROBOTOMY", "PRESIDENTIAL"};
	AForm *forms[3];
	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentialPardonForm(target);
	AForm *final;
	int			i = -1;
	std::size_t	found;

	while(formName[++i])
		upper_name += (char)std::toupper(formName[i]);
	i = -1;
	while (++i < 3)
	{
		found = upper_name.find(formTypes[i]);
		if (found != std::string::npos)
		{
			final = forms[i];
			for (int j = 0; j < 3; j++)
			{
				if (j == i)
					continue;
				delete forms[j];
			}
			return (final);
		}
	}
	for (int j = 0; j < 3; j++)
		delete forms[j];
	return NULL;
}