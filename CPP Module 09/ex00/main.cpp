/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:39:39 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:39:40 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::ifstream	input_file;

	if (argc != 2)
		return std::cerr << "Error: invalid number of arguments. Try \"./btc filename\"\n", 0;
	input_file.open(argv[1]);
	if (!input_file.is_open())
		return std::cerr << "Error: cannot open input file\n", 0;

	try
	{
		BitcoinExchange btc;
		btc.account_btc(input_file);
		//btc.printResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
