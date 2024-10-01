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
#include <map>
#include <stdlib.h>

class BitcoinExchange
{
	private:
		std::map<std::string, float> exchange_rate;
		std::map<std::string, float> transactions;
		std::map<std::string, float> values;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange &original);
		BitcoinExchange &operator=(const BitcoinExchange &original);
		~BitcoinExchange();

		void account_btc(std::ifstream& data, std::ifstream& input);
		void convertDataToMap(std::ifstream& data);
		void convertInputToMap(std::ifstream& data);
};

# endif
