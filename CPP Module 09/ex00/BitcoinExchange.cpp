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
	convertDataToMap(data);
	convertInputToMap(input);
}

void BitcoinExchange::convertDataToMap(std::ifstream& data)
{
	std::string	line;
	std::string	time;
	std::string	num_str;
	float		num;
	int			i;

	while (getline(data, line))
	{
		i = -1;
		while (line[++i] != ',')
			time[i] = line[i];
		while (line[++i])
			num_str[i] = line[i];
		num = std::strtof(num_str.c_str(), NULL);
		exchange_rate.insert(std::pair<std::string, float>(time, num));
	}
}

bool checkLineError(std::string line)
{

}

bool checkTimeError(std::string time)
{

}

bool checkNumberError(std::string num)
{

}

void BitcoinExchange::convertInputToMap(std::ifstream& input)
{
	std::string	line;
	std::string	time;
	std::string	num_str;
	float		num;
	int			i;

	while (getline(input, line))
	{
		if (checkLineError(line))
			continue ;
		i = -1;
		while (line[++i] != '|')
			time[i] = line[i];
		if (checkTimeError(line))
			continue ;
		while (line[++i])
			num_str[i] = line[i];
		num = std::strtof(num_str.c_str(), NULL);
		if (checkNumberError(line))
			continue ;
		transactions.insert(std::pair<std::string, float>(time, num));
	}
}