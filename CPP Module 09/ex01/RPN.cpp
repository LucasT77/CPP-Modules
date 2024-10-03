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
	int buf1 = operands.top();
	operands.pop();
	int buf2 = operands.top();
	operands.pop();
	if (_operator == '-' && buf1 == 0)
		return std::cout << "Error: trying to divide by 0\n", 0;
	switch (_operator)
	{
		case '+': operands.push(buf2 + buf1); break;
		case '-': operands.push(buf2 - buf1); break;
		case '*': operands.push(buf2 * buf1); break;
		case '/': operands.push(buf2 / buf1); break;
		default: return std::cout << "Error: cannot be calculated\n", 0;
			break;
	}
	return 1;
}

bool RPN::calculate(const std::string input, int *final_result)
{
	std::stack<int> operands;
	std::size_t found_operand;
	std::size_t found_operator = 0;
	std::size_t i = 0;
	std::string str = input;

	if (!verifyString(str))
		return std::cout << "Error: bad argument\n", 0;
	while (str[i])
	{
		if (operands.size() == 2)
		{
			if (!calculateResult(operands, str[found_operator]))
				return 0;
			i = 0;
			str = str.substr(found_operator + 1);
			continue ;
		}
		found_operand = (str.substr(i)).find_first_of("0123456789");
		found_operator = str.find_first_of("+-*/");
		if (found_operator < found_operand)
			return std::cout << "Error: bad expression\n", 0;
		for(i = found_operand + 1; str[i] != ' '; i++);
		operands.push(ft_stoi(str.substr(found_operand, i - found_operand)));
	}
	*final_result = operands.top();
	return 1;
}
