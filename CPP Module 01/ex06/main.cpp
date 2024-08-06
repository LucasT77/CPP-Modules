/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:24:07 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:24:11 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	validate_arg(char *arg)
{
	std::string	valid_args[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = -1;

	while (++i < 4)
	{
		if (arg == valid_args[i])
			return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl harl_obj;

	if (argc != 2)
	{
		std::cout << "Invalid number of arguments. Try again with 1 argument\n";
		return (0);
	}
	switch (validate_arg(argv[1]))
	{
		case 0:
			harl_obj.complain("debug");
			harl_obj.complain("info");
			harl_obj.complain("warning");
			harl_obj.complain("error");
			break;
		case 1:
			harl_obj.complain("info");
			harl_obj.complain("warning");
			harl_obj.complain("error");
			break;
		case 2:
			harl_obj.complain("warning");
			harl_obj.complain("error");
			break;
		case 3:
			harl_obj.complain("error");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
