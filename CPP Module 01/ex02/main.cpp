/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:24:07 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:24:11 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout	<< "The memory address of the string variable: " << &str << '\n'
				<< "The memory address held by stringPTR: " << stringPTR << '\n'
				<< "The memory address held by stringREF: " << &stringREF << '\n'
				<< "The value of the string variable: " << str << '\n'
				<< "The value pointed to by stringPTR: " << *stringPTR << '\n'
				<< "The value pointed to by stringREF: " << stringREF << '\n';
}
