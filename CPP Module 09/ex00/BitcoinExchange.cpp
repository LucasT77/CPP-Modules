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

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	data_file;
	if (!data_file.is_open())
		throw BitcoinExchange::DataFileNotFound();
	convertDataToMap(data_file);
}

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

void	BitcoinExchange::account_btc(std::ifstream& input)
{
	convertInputToMap(input);
	std::map<std::string, float>::iterator it_data;
	std::map<std::string, float>::iterator it_input = transactions.begin();
	std::map<std::string, float>::iterator ite_input = transactions.end();
	while (it_input != ite_input)
	{
		if ((*it_input).second == -1)
		{
			makeValue(it_data, it_input);
			it_input++;
			continue ;
		}
		it_data = exchange_rate.lower_bound((*it_input).first);
		if ((*it_data).first != (*it_input).first)
			it_data--;
		makeValue(it_data, it_input);
		it_input++;
	}
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

bool checkLineError(std::string line, std::string *error_str)
{

}

bool checkTimeError(std::string time, std::string *error_str)
{

}

bool checkNumberError(std::string num, std::string *error_str)
{

}

void BitcoinExchange::convertInputToMap(std::ifstream& input)
{
	std::string	line;
	std::string	time;
	std::string	num_str;
	std::string	error_str;
	float		num;
	int			i;
	float		err_id = -1;

	while (getline(input, line))
	{
		if (checkLineError(line, &error_str))
		{
			transactions.insert(std::pair<std::string, float>(error_str, err_id));
			continue ;
		}
		i = -1;
		while (line[++i] != '|')
			time[i] = line[i];
		if (checkTimeError(line, &error_str))
		{
			transactions.insert(std::pair<std::string, float>(error_str, err_id));
			continue ;
		}
		while (line[++i])
			num_str[i] = line[i];
		num = std::strtof(num_str.c_str(), NULL);
		if (checkNumberError(line, &error_str))
		{
			transactions.insert(std::pair<std::string, float>(error_str, err_id));
			continue ;
		}
		transactions.insert(std::pair<std::string, float>(time, num));
	}
}

void BitcoinExchange::makeValue(std::map<std::string, float>::iterator it_data, std::map<std::string, float>::iterator it_input)
{
	std::string final_str;
	float final_num;

	if ((*it_input).second == -1)
	{
		values.insert(std::pair<std::string, float>((*it_input).first, (*it_input).second));
		return ;
	}
	final_str = (*it_input).first + " => " + std::to_string((*it_input).second);
	final_num = (*it_data).second * (*it_input).second;
	values.insert(std::pair<std::string, float>(final_str, final_num));
}

void BitcoinExchange::printResult()
{
	std::map<std::string, float>::iterator it = values.begin();
	std::map<std::string, float>::iterator ite = values.end();

	while (it != ite)
	{
		if ((*it).second == -1)
		{
			std::cout << (*it).first << std::endl;
			continue ;
		}
		std::cout << (*it).first << " = " << (*it).second << std::endl;
		it++;
	}
}

///////Exception///////
const char *BitcoinExchange::DataFileNotFound::what() const throw()
{
    return "Cannot open \"data.csv\" file\n";
}

// const char *BitcoinExchange::CorruptedDataFile::what() const throw()
// {
//     return "Cannot open \"data.csv\" file\n";
// }
