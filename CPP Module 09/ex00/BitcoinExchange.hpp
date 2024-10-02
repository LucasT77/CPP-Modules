/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:40:11 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:40:12 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <sstream> //to perform float to string

class BitcoinExchange
{
	private:
		std::multimap<std::string, float> exchange_rate;
		std::multimap<std::string, float> transactions;
		std::multimap<std::string, float> values;
		void convertDataToMap(std::ifstream& data);
		void convertInputToMap(std::ifstream& data);
		void makeValue(std::multimap<std::string, float>::iterator it_data, std::multimap<std::string, float>::iterator it_input);
		void printLine(std::string time, float num);

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange &original);
		BitcoinExchange &operator=(const BitcoinExchange &original);
		~BitcoinExchange();

		void account_btc(std::ifstream& input);
		void printResult();

		class DataFileNotFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// class CorruptedDataFile : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };
};

# endif
