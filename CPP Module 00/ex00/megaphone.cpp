/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:08:43 by luaraujo          #+#    #+#             */
/*   Updated: 2024/06/27 20:08:48 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	low_to_high_case(char chr)
{
	if (chr >= 97 && chr <= 122)
		return (chr - 32);
	else
		return (chr);
}

int main(int argc, char **argv)
{
	char	chr;
	int		j;

	if (argc < 1)
		return (0);
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		j = -1;
		while (argv[i][++j])
		{
			chr = low_to_high_case(argv[i][j]);
			std::cout << chr;
		}
	}
	std::cout << '\n';
	return (0);
}
