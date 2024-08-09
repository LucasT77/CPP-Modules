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
#include <cmath>

class Fixed
{
	private:
	int _rawBits;
	static const int _bits = 8;	

	public:
	//ex00
	Fixed(void); // A default constructor
	Fixed(Fixed const &fixed_copy); //A copy constructor
	Fixed &operator=(const Fixed &fixed_copy); //A copy assignment operator overload
	~Fixed(void); //A destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);

	//ex01
	Fixed(const int num); //converts integer to fixed-point value
	Fixed(const float num); //converts float to fixed-point value

	float toFloat(void) const; //converts fixed-point value to float
	int toInt(void) const; //converts fixed-point value to int

	//ex02
	bool operator>(const Fixed &copy) const;
	bool operator<(const Fixed &copy) const;
	bool operator>=(const Fixed &copy) const;
	bool operator<=(const Fixed &copy) const;
	bool operator==(const Fixed &copy) const;
	bool operator!=(const Fixed &copy) const;
	Fixed operator+(const Fixed &copy) const;
	Fixed operator-(const Fixed &copy) const;
	Fixed operator*(const Fixed &copy) const;
	Fixed operator/(const Fixed &copy) const;

	Fixed &operator++(void); //preficx
	Fixed operator++(int); //postfix
	Fixed &operator--(void); //prefix
	Fixed operator--(int); //postfix

	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed_num);

#endif
