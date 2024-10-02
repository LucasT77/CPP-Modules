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
		return std::cout << "Invalid number of arguments. Try \"./btc filename\"\n", 0;
	input_file.open(argv[1]);
	if (!input_file.is_open())
		return std::cout << "Cannot open input file\n", 0;

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

/* Practice:
#include <iostream>
#include <string>
#include <map>
#include <iterator>


int main() {
    std::map<std::string, int> bit;
    bit.insert(std::pair<std::string, int>("2011-01-13", 25));
    bit.insert(std::pair<std::string, int>("2011-01-10", 25));
    bit.insert(std::pair<std::string, int>("2008-11-14", 25));

    
    std::map<std::string, int>::iterator itr;
    for (itr = bit.begin(); itr != bit.end(); ++itr)
        std::cout << '\t' << itr->first << '\t' << itr->second << '\n';

    return 0;
}

Output:
2008-11-14	25
2011-01-10	25
2011-01-13	25
*/
