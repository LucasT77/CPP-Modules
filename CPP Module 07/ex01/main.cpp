/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:23:27 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:23:29 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	::iter(arr, 10, print<int>);

	std::string str[] = {"Red", "Green", "Blue"};
	::iter(str, 3, print<std::string>);
}
