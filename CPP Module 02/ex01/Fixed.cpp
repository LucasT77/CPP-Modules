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

//ex01
Fixed::Fixed(const int num)
{
	std::cout << "Fixed number from int function called";
}

Fixed::Fixed(const float num)
{
	std::cout << "Fixed number from float function called";
	_rawBits = std::roundf(num * (1 << Fixed::_bits));
}

float	Fixed::toFloat(void) const
{
	return((float)this->_rawBits / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
{

}

/*std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_num)
{

}*/