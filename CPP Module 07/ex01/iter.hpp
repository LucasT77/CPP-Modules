/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:24:26 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:24:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(arr[i]);
}

template <typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

#endif
