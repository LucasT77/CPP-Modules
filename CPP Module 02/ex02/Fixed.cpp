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
	//std::cout << "Default constructor called\n";
	_rawBits = 0;
}

Fixed::Fixed(Fixed const &fixed_copy)
{
	//std::cout << "Copy constructor called\n";
	*this = fixed_copy;
}

Fixed	&Fixed::operator=(const Fixed &fixed_copy)
{
	//std::cout << "Copy assignment operator calle\n";
	this->_rawBits = fixed_copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n";
	this->_rawBits = raw;
}

//////////////////////////////////EX01//////////////////////////////////////////

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	_rawBits = num << Fixed::_bits;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
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

//////////////////////////////////EX02//////////////////////////////////////////

bool	Fixed::operator>(const Fixed &copy) const
{
	return this->_rawBits > copy._rawBits;
}
bool	Fixed::operator<(const Fixed &copy) const
{
	return this->_rawBits < copy._rawBits;
}
bool	Fixed::operator>=(const Fixed &copy) const
{
	return this->_rawBits >= copy._rawBits;
}
bool	Fixed::operator<=(const Fixed &copy) const
{
	return this->_rawBits <= copy._rawBits;
}
bool	Fixed::operator==(const Fixed &copy) const
{
	return this->_rawBits == copy._rawBits;
}
bool	Fixed::operator!=(const Fixed &copy) const
{
	return this->_rawBits != copy._rawBits;
}


Fixed	Fixed::operator+(const Fixed &copy) const
{
	Fixed result;

	result._rawBits = this->_rawBits + copy._rawBits;
	return (result);
}
Fixed	Fixed::operator-(const Fixed &copy) const
{
	Fixed result;

	result._rawBits = this->_rawBits - copy._rawBits;
	return (result);
}
Fixed	Fixed::operator*(const Fixed &copy) const
{
	Fixed result;

	result._rawBits = (this->_rawBits * copy._rawBits) >> _bits;
	return (result);
}
Fixed	Fixed::operator/(const Fixed &copy) const
{
	Fixed result;

	result._rawBits = (this->_rawBits << _bits) / copy._rawBits;
	return (result);
}



Fixed	&Fixed::operator++(void)
{
	++this->_rawBits;
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed fixed(this->_rawBits * toFloat());
	++this->_rawBits;
	return (fixed);
}
Fixed	&Fixed::operator--(void)
{
	--this->_rawBits;
	return (*this);
}
Fixed	Fixed::operator--(int)
{
	Fixed fixed(this->_rawBits * toFloat());
	--this->_rawBits;
	return (fixed);
}


Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.operator>(fixed2))
		return (fixed2);
	return (fixed1);
}
const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.operator>(fixed2))
		return (fixed2);
	return (fixed1);
}
Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.operator<(fixed2))
		return (fixed2);
	return (fixed1);
}
const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.operator<(fixed2))
		return (fixed2);
	return (fixed1);
}
