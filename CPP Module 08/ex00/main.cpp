/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:32:00 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:32:02 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    bool x;
    std::vector<int> numbers;

	for(int i = 0; i < 10; i++)
		numbers.push_back(i);

    try
    {
		x = easyfind(numbers, 3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (x)
		std::cout << "Element found\n";
	try
    {
		x = easyfind(numbers, 13);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
