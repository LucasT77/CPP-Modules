/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:12:57 by luaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 15:13:03 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact _contact[8];
	int		_index = 0;

	public:
    void	add(void);
	void	search(void);
	void	exit(void); 
	void	get_list(int index);
	std::string	get_cell(std::string str);
	void	open_contact(int index);
};

#endif