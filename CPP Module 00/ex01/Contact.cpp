/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:16:31 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/01 20:16:33 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::setFirstName(std::string fn)
{
    firstName = fn;
}

void Contact::setLastName(std::string ln)
{
    lastName = ln;
}

void Contact::setNickname(std::string nn)
{
    nickname = nn;
}

void Contact::setPhoneNumber(std::string pn)
{
    phoneNumber = pn;
}

void Contact::setDarkestSecret(std::string ds)
{
    darkestSecret = ds;
}

std::string Contact::getFirstName()
{
    return (firstName);
}

std::string Contact::getLastName()
{
    return (lastName);
}

std::string Contact::getNickname()
{
    return (nickname);
}

std::string Contact::getPhoneNumber()
{
    return (phoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (darkestSecret);
}