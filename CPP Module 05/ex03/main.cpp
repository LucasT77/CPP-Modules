/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:59:43 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 14:59:45 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"
#include "headers/Intern.hpp"

int main()
{
	std::cout << "\n\n/////////////////////////EX00/////////////////////////\n" << std::endl;
	
	Bureaucrat b1;
	Bureaucrat b2("Steve", 1);
	Bureaucrat b3(b2);
	Bureaucrat b4;

	b4 = b1;
	b1.incrementGrade();

	std::cout << std::endl;
	
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;

	std::cout << std::endl;

	try
	{
		b4.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		b2.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << b2;
	std::cout << b4;

	std::cout << std::endl;

	try
	{
		Bureaucrat b5("Oliver", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//std::cout << b5 << std::endl;



	std::cout << "\n\n/////////////////////////EX01/////////////////////////\n" << std::endl;

	//PresidentialPardon f1("Blank", 80, 50);
	// Bureaucrat b6("John", 90);
	// Bureaucrat b7("Peter", 30);

	// std::cout << std::endl;

	// b6.executeForm(f1);
	// try
	// {
	// 	f1.beSigned(b6);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// std::cout << f1;
	
	// try
	// {
	// 	f1.beSigned(b7);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// std::cout << f1;

	// std::cout << std::endl;

	// b6.signForm(f1);
	// b7.signForm(f1);
	
	// std::cout << "Test of ex01 no longer works, becuse Form has turned int an abstract class.";


	std::cout << "\n\n/////////////////////////EX02/////////////////////////\n" << std::endl;

	Bureaucrat b6("John", 90);
	Bureaucrat b7("Peter", 30);
	Bureaucrat b8("Susan", 3);
	ShrubberyCreationForm	shrub;
	RobotomyRequestForm		robot("Alex Murphy");
	PresidentialPardonForm	pardon;

	std::cout << std::endl;

	b6.signForm(shrub);
	b6.signForm(robot);
	b6.signForm(pardon);

	b6.executeForm(shrub);
	b6.executeForm(robot);
	b6.executeForm(pardon);
	
	std::cout << std::endl;

	b7.signForm(shrub);
	b7.signForm(robot);
	b7.signForm(pardon);

	b7.executeForm(shrub);
	b7.executeForm(robot);
	b7.executeForm(pardon);
	
	std::cout << std::endl;

	b8.signForm(shrub);
	b8.signForm(robot);
	b8.signForm(pardon);

	b8.executeForm(shrub);
	b8.executeForm(robot);
	b8.executeForm(pardon);
	
	std::cout << std::endl;


	std::cout << "\n\n/////////////////////////EX03/////////////////////////\n" << std::endl;

	Intern mike;
	AForm *p;
	Bureaucrat b9("Carl", 4);

	p = mike.makeForm("presidential", "Gold King");
	if (!p)
	{
		std::cout << "Error: the form does not exist\n";
		return 0;
	}

	std::cout << std::endl;

	b9.signForm(*p);
	b9.executeForm(*p);
	
	std::cout << std::endl;
}



