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
	data_file.open("data.csv");
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
	std::multimap<std::string, float>::iterator it_data;
	std::multimap<std::string, float>::iterator it_input = transactions.begin();
	std::multimap<std::string, float>::iterator ite_input = transactions.end();
	while (it_input != ite_input)
	{
		it_data = exchange_rate.lower_bound((*it_input).first);
		if ((*it_data).first != (*it_input).first)
			it_data--;
		makeValue(it_data, it_input);
		it_input++;
	}
}

void BitcoinExchange::printResult()
{
	std::multimap<std::string, float>::iterator it = values.begin();
	std::multimap<std::string, float>::iterator ite = values.end();

	while (it != ite)
	{
		if ((*it).second == -1)
		{
			std::cout << (*it).first << std::endl;
			it++;
			continue ;
		}
		std::cout << (*it).first << " = " << (*it).second << std::endl;
		it++;
	}
}

void BitcoinExchange::printLine(std::string time, float num)
{
	if (num == -1)
	{
		std::cout << time << std::endl;
		return ;
	}
	std::multimap<std::string, float>::iterator it_data;
	it_data = exchange_rate.lower_bound(time);
	if ((*it_data).first != time)
		it_data--;
	std::cout << time << " => " << num << " = " << num * (*it_data).second << std::endl;
}

///////Utils///////

void BitcoinExchange::convertDataToMap(std::ifstream& data)
{
	std::string	line;
	std::string	time;
	std::string	num_str;
	float		num;

	while (getline(data, line))
	{
		time = line.substr(0, 10);
		num_str = line.substr(11);
		num = std::strtof(num_str.c_str(), NULL);
		exchange_rate.insert(std::pair<std::string, float>(time, num));
	}
}

bool checkLineError(std::string line, std::string *error_str)
{
	std::string	buffer;
	float		n_buf;
	char		*end;

	buffer = line.substr(0, 5); //year + '-'
	n_buf = std::strtof(buffer.c_str(), &end);
	if (end[0] != '-' || end[1] || (n_buf < 2009 || n_buf > 2024))
		return *error_str = "Error: bad input => " + line, 1;
	buffer = line.substr(5, 3); //month + '-'
	n_buf = std::strtof(buffer.c_str(), &end);
	if (end[0] != '-' || end[1] || (n_buf < 1 || n_buf > 12))
		return *error_str = "Error: bad input => " + line, 1;
	buffer = line.substr(8, 3); //day + ' '
	n_buf = std::strtof(buffer.c_str(), &end);
	if (end[0] != ' ' || end[1] || (n_buf < 1 || n_buf > 31))
		return *error_str = "Error: bad input => " + line, 1;
	buffer = line.substr(11, 2); //day + ' '
	if (buffer[0] != '|' || buffer[1] != ' ')
		return *error_str = "Error: bad input => " + line, 1;
	return 0;
}

bool checkErrorDate(float year, float month, float day)
{
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		return 1;
	if (year == 2009 && month == 1 && day < 2)
		return 1;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return 1;
	if (month == 2)
	{
		if ((year == 2012 || year == 2016 || year == 2020 || year == 2024) && day == 29)
			return 0;
		else if(day > 28)
			return 1;
	}
	return 0;
}

bool checkTimeError(std::string time, std::string *error_str)
{
	float year = std::strtof(time.substr(0, 4).c_str(), NULL);
	float month = std::strtof(time.substr(5, 2).c_str(), NULL);
	float day = std::strtof(time.substr(8, 2).c_str(), NULL);
	if (checkErrorDate(year, month, day))
		return *error_str = "Error: bad input => " + time, 1;
	return 0;
}

bool checkNumberError(float num, std::string *error_str)
{
	if(num < 0)
		return *error_str = "Error: not a positive number.", 1;
	if (num > 1000)
		return *error_str = "Error: too large a number.", 1;
	return 0;
}



void BitcoinExchange::convertInputToMap(std::ifstream& input)
{
	std::string	line;
	std::string	time;
	std::string	num_str;
	std::string	error_str;
	float		num;
	float		err_id = -1;

	while (getline(input, line))
	{
		if (checkLineError(line, &error_str))
		{
			printLine(error_str, err_id);
			continue ;
		}
		time = line.substr(0, 10);
		if (checkTimeError(time, &error_str))
		{
			printLine(error_str, err_id);
			continue ;
		}
		num_str = line.substr(13);
		num = std::strtof(num_str.c_str(), NULL);
		if (checkNumberError(num, &error_str))
		{
			printLine(error_str, err_id);
			continue ;
		}
		transactions.insert(std::pair<std::string, float>(time, num));
		printLine(time, num);
	}
}

void BitcoinExchange::makeValue(std::multimap<std::string, float>::iterator it_data, std::multimap<std::string, float>::iterator it_input)
{
	std::string final_str;
	float final_num;

	std::ostringstream ss;
	ss << (*it_input).second;
	std::string s(ss.str());

	final_str = (*it_input).first + " => " + s;
	final_num = (*it_data).second * (*it_input).second;
	values.insert(std::pair<std::string, float>(final_str, final_num));
}


///////Exception///////
const char *BitcoinExchange::DataFileNotFound::what() const throw()
{
    return "Cannot open \"data.csv\" file\n";
}
