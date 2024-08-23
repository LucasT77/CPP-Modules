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

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern &other) {}
Intern &Intern::operator=(const Intern &other) {}
Intern::~Intern() {}

Form *Intern::makeForm(std::string formName, std::string target)
{
	std::string	upper_name;
	std::string	formTypes[3] = {"SHRUBBERY", "ROBOTOMY", "PRESIDENTIAL"};
	Form *forms[3] = {new ShrubberyCreationForm, new RobotomyRequestForm, new PresidentialPardonForm};
	Form *final;
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
			final.setTarget(target);
			delete [] forms;
			return (final);
		}
	}
	delete [] forms;
	std::cout << "Form not found\n";
	return NULL;
}
