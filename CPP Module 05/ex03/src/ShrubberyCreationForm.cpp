/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:03:12 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:03:14 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ShrubberyCreationForm.hpp"

////////////////////////////////Constructors & Destructor////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	Target = "Home";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	Target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	this->Target = other.Target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

////////////////////////////////Methods////////////////////////////////////////////////////////////////

void ShrubberyCreationForm::execution() const
{
	std::string filename;
	std::ofstream new_file;

	filename = Target + "_shrubbery";
	new_file.open(filename.c_str());
	if (new_file.is_open() == false)
	{
		std::cout << "Error creating new file\n";
		return ;
	}
	new_file	<<	"      '.,\n"
				<<	"        'b      *\n"
				<<	"         '$    #.\n"
				<<	"          $:   #:\n"
				<<	"          *#  @):\n"
				<<	"          :@,@):   ,.**:'\n"
				<<	",         :@@*: ..**'\n"
				<<	" '#o.    .:(@'.@*''\n"
				<<	"    'bq,..:,@@*'   ,*\n"
				<<	"    ,p$q8,:@)'  .p*'\n"
				<<	"   '    '@@Pp@@*'\n"
				<<	"         Y7'.'\n"
				<<	"        :@):.\n"
				<<	"       .:@:'.\n"
				<<	"     .::(@:.\n          -Sam Blumenstein-";
}
