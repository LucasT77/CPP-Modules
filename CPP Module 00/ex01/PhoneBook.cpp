/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:14:13 by luaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 15:14:15 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add(void)
{
	std::string str;

	std::cout << "To save a contact please provide the following information:\n";
	std::cout << "First name:\n";
	std::cin >> str;
	_contact[_index % 8].setFirstName(str);
	std::cout << "Last name:\n";
	std::cin >> str;
	_contact[_index % 8].setLastName(str);
	std::cout << "Nickname:\n";
	std::cin >> str;
	_contact[_index % 8].setNickname(str);
	std::cout << "Phone number:\n";
	std::cin >> str;
	_contact[_index % 8].setPhoneNumber(str);
	std::cout << "Darkest secret:\n";
	std::cin >> str;
	_contact[_index % 8].setDarkestSecret(str);
	_index++;
}

std::string PhoneBook::make_cell(std::string str)
{
	size_t	len;
	std::string	new_str;
	int		i = -1;
	
	len = str.length();
	if (len == 10)
	{
		return (str);
	}
	else if (len > 10)
	{
		while (++i < 9)
			new_str += str[i];
		new_str += '.';
	}
	else if (len < 10)
	{
		while (++i < 10 - len)
			new_str += ' ';
		i--;
		while (++i < 10)
			new_str += str[i - (10 - len)];
	}
	return (new_str);
}

void PhoneBook::make_list(int index)
{
	int	i = -1;
	int	aux;
	std::string index_output;

	std::cout << '\n' << '|' << make_cell("index") << '|' << make_cell("First Name") << '|' 
				<< make_cell("Last Name") << '|' << make_cell("Nickname") << '|' << '\n';
	while (++i < index)
	{
		aux = i + 1;
		index_output = aux + '0';
		std::cout << '|' << make_cell(index_output) << '|' << make_cell(_contact[i].getFirstName()) << '|' 
					<< make_cell(_contact[i].getLastName()) << '|' << make_cell(_contact[i].getNickname()) << '|' << '\n';
	}
	std::cout << '\n';
}

void PhoneBook::open_contact(int index)
{
	std::cout << "First name: " << _contact[index].getFirstName() << "\n";
	std::cout << "Last name: " << _contact[index].getLastName() << "\n";
	std::cout << "Nickname: " << _contact[index].getNickname() << "\n";
	std::cout << "Phone number: " << _contact[index].getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << _contact[index].getDarkestSecret() << "\n";
}

void PhoneBook::search(void)
{
	int	index_input;
	int tries = 0;
	int	index;

	index = _index;
	if (index > 8)
		index = 8;
	make_list(index);
	std::cout << "Insert the index of the desired contact information:\n";
	while (tries < 3)
	{
		if ((std::cin >> index_input) && (index_input > 0 && index_input <= index)) break ;
		std::cout << "Index out of range. ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		tries++;
		if (tries < 3) std::cout << "Try again:\n";
	}
	if ((index_input < 1 || index_input > index) && tries > 2)
	{
		std::cout << "\nLimit of attempts reached. Returning to main menu...\n" << "...\n" << "...\n";
		return ;
	}
	open_contact(index_input - 1);
}
