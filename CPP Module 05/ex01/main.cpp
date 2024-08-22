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

#include "Bureaucrat.hpp"

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

	Form f1("Blank", 80, 50);
	Bureaucrat b6("John", 90);
	Bureaucrat b7("Peter", 30);

	std::cout << std::endl;

	try
	{
		f1.beSigned(b6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << f1;
	
	try
	{
		f1.beSigned(b7);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << f1;

	std::cout << std::endl;

	b6.signForm(f1);
	b7.signForm(f1);

	std::cout << std::endl;


	
	
}
