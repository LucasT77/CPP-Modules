/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:39:03 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/06 19:39:05 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int fixed_num;
	static const int fraction_bits = 8;	

	public:
	Fixed(void); // A default constructor
	Fixed(Fixed &fixed_copy); //A copy constructor
	Fixed operator+(const Fixed &fixed_copy); //A copy assignment operator overload
	~Fixed(void); //A destructor
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
