/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:11:47 by luaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 15:11:49 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

using namespace std;

int main(void)
{
	PhoneBook PB1;
	std:string input;

	std::cout	<< "Welcome to the most AWESOME ***PhoneBook*** in the GALAXY!!!\n"
				<< "There are three commands:\n"
				<< "*ADD* to add a new contact (remember: there can only be 8 contacts, any more and the older ones will be erased)\n"
				<< "*SEARCH* to search for a contact in the list\n"
				<< "*EXIT* to exit the BEST PhoneBook in the UNIVERSE! (remember: all contacts will be erased)";

	while (input != "EXIT")
	{
		std::cout << "Please enter you command:\n";
		std::cin >> input;
		if (input == "ADD")
			PB1.add();
		else if (input == "SEARCH")
			PB1.search();
		else if (input == "EXIT")
			PB1.exit();
		else
		{
			std::cout << "Wrong Command. Try ADD, SEARCH or EXIT.\n";
			continue ;
		}
	}
}
