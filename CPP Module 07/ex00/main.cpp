/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:22:14 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:22:16 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void testInt()
{
	int a = 5, b = 7;
	std::cout	<< "/////Test type int/////\n";
	std::cout	<< "Before swap:\n"
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl;
	swap<int>(&a, &b);
	std::cout	<< "After swap:\n"
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl
				<< "min(a,b) = " << min<int>(a, b) << std::endl
				<< "max(a,b) = " << max<int>(a, b) << std::endl;
}

void testChar()
{
	char a = 'x', b = 'y';
	std::cout	<< "/////Test type char/////\n";
	std::cout	<< "Before swap:\n"
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl;
	swap<char>(&a, &b);
	std::cout	<< "After swap:\n"
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl
				<< "min(a,b) = " << min<char>(a, b) << std::endl
				<< "max(a,b) = " << max<char>(a, b) << std::endl;
}

void testString()
{
	std::string a = "Hello";
	std::string b = "World";
	std::cout	<< "/////Test type std::string/////\n";
	std::cout	<< "Before swap:\n"
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl;
	swap<std::string>(&a, &b);
	std::cout	<< "After swap:\n"
				<< "a = " << a << std::endl
				<< "b = " << b << std::endl
				<< "min(a,b) = " << ::min<std::string>(a, b) << std::endl
				<< "max(a,b) = " << ::max<std::string>(a, b) << std::endl;
}

int main()
{
	testInt();
	testChar();
	testString();
}
