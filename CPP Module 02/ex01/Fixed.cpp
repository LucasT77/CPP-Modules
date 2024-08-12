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

//////////////////////////////////EX00//////////////////////////////////////////

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	_rawBits = 0;
}

Fixed::Fixed(Fixed const &fixed_copy)
{
	std::cout << "Copy constructor called\n";
	*this = fixed_copy;
}

Fixed	&Fixed::operator=(const Fixed &fixed_copy)
{
	std::cout << "Copy assignment operator called\n";
	this->_rawBits = fixed_copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

//////////////////////////////////EX01//////////////////////////////////////////

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = num << Fixed::_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(num * (1 << Fixed::_bits));
}

float	Fixed::toFloat(void) const
{
	return((float)this->_rawBits / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
{
	return ((int)this->_rawBits >> Fixed::_bits);
}

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed_num)
{
	return (COUT << fixed_num.toFloat());
}