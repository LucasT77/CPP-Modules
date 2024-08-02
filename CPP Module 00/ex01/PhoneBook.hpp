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
	Contact 	_contact[8];
	int			_index = 0;
	void		make_list(int index);
	void		open_contact(int index);
	std::string	make_cell(std::string str);

	public:
    void		add(void);
	void		search(void);
};

#endif