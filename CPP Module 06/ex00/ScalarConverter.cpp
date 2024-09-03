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

///////Constructors & Destructor

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) 
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

///////Utils (Not part of class)

bool isPseudo(double d)
{
	double inf = std::numeric_limits<double>::infinity();

	if (d == inf || d == -inf || std::isnan(d))
		return true;
	return false;
}

bool check_zero(std::string str)
{
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

	if (var_double == 0 || (var_double < 0 || var_double > 255) || isPseudo(var_double) == true)
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

	if (var_double == 0 || isPseudo(var_double) == true)
	{
		std::cout << "int: " << "impossible" << std::endl;
		return ;
	}
	n = static_cast<int>(var_double);
	std::cout << "int: " << n << std::endl;
}

bool isWhole(double var_double)
{
	int n = static_cast<int>(var_double);
	double aux = var_double - n;
	if (aux == 0)
		return true;
	return false;
}

std::string floatAdditions(double var_double)
{
	std::string adds;
	if (isWhole(var_double) == true)
		adds = ".0";
	adds += "f";
	return adds;
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
	std::cout << "float: " << n << floatAdditions(var_double) << std::endl;
}

std::string doubleAdditions(double var_double)
{
	std::string adds;
	if (isWhole(var_double) == true)
		adds = ".0";
	else
		adds = "";
	return adds;
}

void print_double(double var_double)
{
	if (var_double == 0)
	{
		std::cout << "double: " << "impossible" << std::endl;
		return ;
	}
	std::cout << "double: " << var_double << doubleAdditions(var_double) << std::endl;
}

void impossible_or_0(bool i)
{
	if (!i)
	{
		std::cout << "char: " << "Non displayable" << std::endl;
		std::cout << "int: " << 0 << std::endl;
		std::cout << "float: " << "0.0f" << std::endl;
		std::cout << "double: " << "0.0" << std::endl;
		return ;
	}
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string str)
{
	char		*end;
	double		var_double;

	if(check_zero(str) == 0)
		return impossible_or_0(0);
	var_double = std::strtod(str.c_str(), &end);
	if (end[0] != 0 && (end[0] != 'f' || end[1] != 0))
		return impossible_or_0(1) ;
	print_char(var_double);
	print_int(var_double);
	print_float(var_double);
	print_double(var_double);
}
