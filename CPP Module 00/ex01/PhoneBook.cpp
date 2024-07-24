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
	std::cin << _contact[_index].firstName;
	std::cout << "Last name:\n";
	std::cin << _contact[_index].lastName;
	std::cout << "Nickname:\n";
	std::cin << _contact[_index].nickname;
	std::cout << "Phone number:\n";
	std::cin << _contact[_index].phoneNumber;
	std::cout << "Darkest secret:\n";
	std::cin << _contact[_index].darkestSecret;
	_index++
}

string get_cell(string str)
{
	size_t	len;
	string	new_str[10];
	int		i = -1;
	
	len = strlen(str);
	if (len = 10)
		return (str);
	else if (len > 10)
	{
		while (++i < 9)
			new_string[i] = str[i];
		new_string[i] = '.';
	}
	else if (len < 10)
	{
		while (++i < 10 - len)
			new_string[i] = ' ';
		i--;
		while (++i < 10)
			new_str[i] = str[i - (10 - len)];
	}
	return (new_str);
}

void	get_list(int index)
{
	int	i = 0;

	std::cout << get_cell("index") + '|' + get_cell("First Name") + '|' + get_cell("Last Name") + '|' + get_cell("Nickname") + '\n';
	while (++i <= index)
	{
		std::cout << 
	}
}

void PhoneBook::search(void)
{
	get_list(_index)
}
