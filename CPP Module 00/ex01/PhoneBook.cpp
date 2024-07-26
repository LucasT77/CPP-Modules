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
	if (_index == 8)
		_index = 0;
	std::cout << "To save a contact please provide the following information:\n";
	std::cout << "First name:\n";
	std::cin >> _contact[_index].firstName;
	std::cout << "Last name:\n";
	std::cin >> _contact[_index].lastName;
	std::cout << "Nickname:\n";
	std::cin >> _contact[_index].nickname;
	std::cout << "Phone number:\n";
	std::cin >> _contact[_index].phoneNumber;
	std::cout << "Darkest secret:\n";
	std::cin >> _contact[_index].darkestSecret;
	_index++;
}

std::string PhoneBook::get_cell(std::string str)
{
	size_t	len;
	std::string	new_str;
	int		i = -1;
	
	len = str.length();
	if (len = 10)
		return (str);
	else if (len > 10)
	{
		while (++i < 9)
			new_str[i] = str[i];
		new_str[i] = '.';
	}
	else if (len < 10)
	{
		while (++i < 10 - len)
			new_str[i] = 32;
		i--;
		while (++i < 10)
			new_str[i] = str[i - (10 - len)];
	}
	return (new_str);
}

void PhoneBook::get_list(int index)
{
	int	i = 0;
	int	aux;
	std::string index_output;

	std::cout << get_cell("index") << '|' << get_cell("First Name") << '|' 
				<< get_cell("Last Name") << '|' << get_cell("Nickname") << '\n';
	while (++i <= index)
	{
		aux = i + 1;
		index_output = aux + '0';
		std::cout << get_cell(index_output) << '|' << get_cell(_contact[i].firstName) << '|' 
					<< get_cell(_contact[i].lastName) << '|' << get_cell(_contact[i].nickname) << '\n';
	}
}

void PhoneBook::open_contact(int index)
{
	std::cout << "First name: " << _contact[index].firstName << "\n";
	std::cout << "Last name: " << _contact[index].lastName << "\n";
	std::cout << "Nickname: " << _contact[index].nickname << "\n";
	std::cout << "Phone number: " << _contact[index].phoneNumber << "\n";
	std::cout << "Darkest secret: " << _contact[index].darkestSecret << "\n";
}

void PhoneBook::search(void)
{
	int	index_input;
	int tries = 0;

	get_list(_index);
	std::cout << "Insert the index of the desired contact information:\n";
	std::cin >> index_input;
	while ((index_input < 1 || index_input > _index + 1) && tries < 3)
	{
		std::cout << "Index out of range. Try again";
		std::cin >> index_input;
		tries++;
	}
	if ((index_input < 1 || index_input > _index + 1) && tries == 3)
	{
		std::cout << "Limit of attempts reached. Returning to main menu...\n" << "...\n" << "...\n";
		return ;
	}
	if (index_input >= 1 || index_input <= _index + 1)
		open_contact(index_input - 1);
}
