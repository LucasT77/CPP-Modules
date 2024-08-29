/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:05:35 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/27 17:05:37 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) 
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

bool check_zero(std::string str)
{
	// for (int i = 0; str[i]; i++)
	// {
	// 	if (str[i] == 32)
	// 		continue;
	// 	if (str[i] != '0')
	// 		return 1;
	// 	if (str[i] == '0')
	// 	{
	// 		if (!str[i + 1])
	// 			return 0;
	// 		if (str[i + 1] != '.')
	// 			return 1;
	// 		i += 2;
	// 		while (str[i])
	// 			if (str[i] != '0')
	// 				return 1;
	// 		return 0;
	// 	}
	// }

	int  i = 0;
	if (str[i] == '0')
	{
		i++;
		if (str[i] && str[i] != '.')
			return 1;
		else if (!str[i])
			return 0;
		else
			i++;
		while (str[i] == '0')
			i++;
		if (!str[i])
			return 0;
	}
	return 1;
}

void print_char(double var_double)
{
	char c;

	if (var_double == 0 || (var_double < 0 || var_double > 255))
	{
		std::cout << "char: " << "impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(var_double);
	if (c >= 0 && c <= 31)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void print_int(double var_double)
{
	int n;

	if (var_double == 0)
	{
		std::cout << "int: " << "impossible" << std::endl;
		return ;
	}
	n = static_cast<int>(var_double);
	std::cout << "int: " << n << std::endl;
}

void print_float(double var_double)
{
	float n;

	if (var_double == 0)
	{
		std::cout << "float: " << "impossible" << std::endl;
		return ;
	}
	n = static_cast<float>(var_double);
	std::cout << "float: " << n << std::endl;
}

void print_double(double var_double)
{
	if (var_double == 0)
	{
		std::cout << "double: " << "impossible" << std::endl;
		return ;
	}
	std::cout << "double: " << var_double << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	const char	*str_array;
	double		var_double;

	if(check_zero(str) == 0)
	{
		std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << 0 << std::endl;
		std::cout << "float: " << "0.0f" << std::endl;
		std::cout << "double: " << "0.0" << std::endl;
		return ;
	}
	str_array = str.c_str();
	var_double = atof(str_array);
	print_char(var_double);
	print_int(var_double);
	print_float(var_double);
	print_double(var_double);	

	//missing the details, execeptions, what happens when str cannot be converted to a certain type
}
