/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:40:03 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:40:05 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


///////Constructors & Destructor///////

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other) { *this = other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->exchange_rate = other.exchange_rate;
	this->transactions = other.transactions;
	this->values = other.values;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


///////Methods///////

void	BitcoinExchange::account_btc(std::ifstream& data, std::ifstream& input)
{
	
}
