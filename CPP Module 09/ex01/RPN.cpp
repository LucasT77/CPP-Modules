/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:47:02 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:47:07 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

///////CONSTRUCTORS///////

RPN::RPN() {}
RPN::RPN(RPN &other) {(void)other;}
RPN &RPN::operator=(const RPN &other) 
{
	(void)other;
	return *this;
}
RPN::~RPN() {}

///////METHODS///////

bool verifyString(const std::string str)
{
	bool verify = true;
	std::size_t pos1;
	std::size_t pos2;

	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		verify = false;
	if (str.find_first_of("+-*/") == std::string::npos)
		verify = false;
	pos1 = str.find_first_of("0123456789");
	pos2 = str.find_last_of("0123456789");
	if (pos1 == std::string::npos || pos2 == std::string::npos || pos1 == pos2)
		verify = false;
	return verify;
}

int ft_stoi(const std::string str)
{
	int num;
	std::stringstream ss(str);
    ss >> num;
    return num;
}

bool calculateResult(std::stack<int> &operands, char _operator)
{
	if (operands.size() < 2)
		return 0;
	int buf1 = operands.top();
	operands.pop();
	int buf2 = operands.top();
	operands.pop();
	if (_operator == '/' && buf1 == 0)
		return std::cerr << "Error: trying to divide by 0\n", 0;
	switch (_operator)
	{
		case '+': operands.push(buf2 + buf1); break;
		case '-': operands.push(buf2 - buf1); break;
		case '*': operands.push(buf2 * buf1); break;
		case '/': operands.push(buf2 / buf1); break;
		default: return std::cerr << "Error: cannot be calculated\n", 0;
			break;
	}
	return 1;
}

bool RPN::calculate(const std::string input, int *final_result)
{
	std::stack<int> operands;
	std::size_t i = 0;
	std::string str = input;
	std::string num;

	if (!verifyString(str))
		return std::cerr << "Error: bad argument\n", 0;
	while (str[i])
	{
		while ((str.substr(i)).find_first_of("0123456789") == 0)
			num += str[i++];
		if (!num.empty())
		{
			operands.push(ft_stoi(num));
			num.clear();
		}
		if ((str.substr(i)).find_first_of("+-*/") == 0)
		{
			if (operands.size() < 2)
				return std::cerr << "Error: bad expression\n", 0;
			if (!calculateResult(operands, str[i]))
				return 0;
			i++;
			continue ;
		}
		i++;
	}
	if (operands.size() != 1)
		return std::cerr << "Error: bad expression\n", 0;
	*final_result = operands.top();
	return 1;
} 
