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


void	ScalarConverter::convert(std::string str)
{
	const char	*str_array;
	char		var_char;
	int			var_int;
	float		var_float;
	double		var_double;

	//if(str == "0")
	str_array = str.c_str();
	var_double = atof(str_array);
	var_float = static_cast<float>(var_double);
	var_int = static_cast<int>(var_double);
	var_char = static_cast<char>(var_int);

	//missing the details, execeptions, what happens when str cannot be converted to a certain type
	
	std::cout << "char: " << var_char << std::endl;
	std::cout << "int: " << var_int << std::endl;
	std::cout << "float: " << var_float << std::endl;
	std::cout << "double: " << var_double << std::endl;
}
