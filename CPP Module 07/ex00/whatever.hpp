/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:22:53 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:22:55 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T *x, T *y)
{
	T buf;
	buf = *x;
	*x = *y;
	*y = buf;
}

template <typename T>
T min(T x, T y)
{
	return (x < y) ? x : y;
}

template <typename T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}

#endif
