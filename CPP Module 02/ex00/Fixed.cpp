/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:38:52 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/06 19:38:55 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	_rawBits = 0;
}

Fixed::Fixed(Fixed &fixed_copy)
{
	std::cout << "Copy constructor called\n";
	*this = fixed_copy;
}

Fixed	&Fixed::operator=(const Fixed &fixed_copy)
{
	std::cout << "Copy assignment operator calle\n";
	this->_rawBits = fixed_copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}