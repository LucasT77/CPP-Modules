/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:46:48 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:46:51 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	int result;

	if (argc != 2)
		return std::cout << "Wrong number of arguments. There must be two.\n", 0;
	if (RPN::calculate(argv[1], &result))
		std::cout << result << std::endl;
}
