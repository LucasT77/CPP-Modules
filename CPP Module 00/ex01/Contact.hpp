/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:14:44 by luaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 15:14:46 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	public:
	void	setFirstName(std::string fn);
	void	setLastName(std::string ln);
	void	setNickname(std::string nn);
	void	setPhoneNumber(std::string pn);
	void	setDarkestSecret(std::string ds);
	void	getFirstName(std::string fn);
	void	getLastName(std::string ln);
	void	getNickname(std::string nn);
	void	getPhoneNumber(std::string pn);
	void	getDarkestSecret(std::string ds);
};

#endif