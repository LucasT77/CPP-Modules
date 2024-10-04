/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:49:03 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:49:09 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
		return std::cout << "Error: insufficient number of arguments\n", 0;

    argv++;
	argc--;
    PmergeMe::sort(argc, argv);
}
