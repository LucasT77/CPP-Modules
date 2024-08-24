/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:04:45 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:04:46 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class AForm;
class ShubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{  
	public:
		// Intern();
		// Intern(Intern &other);
		// Intern &operator=(const Intern &other);
		// ~Intern();

		AForm *makeForm(std::string formName, std::string target);
};

#endif
