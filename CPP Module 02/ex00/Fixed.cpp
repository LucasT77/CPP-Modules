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
	fixed_num = 0;
}

Fixed::Fixed(Fixed &fixed_copy)
{

}

Fixed	Fixed::operator=(const Fixed &fixed_copy)
{

}

Fixed::~Fixed(void)
{

}

int		Fixed::getRawBits(void) const
{
	return (this->fixed_num);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_num = raw;
}
