/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:30:51 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:30:52 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{

}

Harl::~Harl(void)
{
    
}

void	Harl::debug(void)
{
	std::cout	<< "DEBUG:\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
				<<	"ketchup burger. I really do!" << '\n';
}

void	Harl::info(void)
{
	std::cout	<< "INFO:\n"
				<< "I cannot believe adding extra bacon costs more money. You did not put "
				<<	"enough bacon in my burger! If you did, I would not be asking for more!" << '\n';
}

void	Harl::warning(void)
{
	std::cout	<< "WARNING:\n"
				<< "I think I deserve to have some extra bacon for free. I have been coming for "
				<<	"years whereas you started working here since last month." << '\n';
}

void	Harl::error(void)
{
	std::cout	<< "ERROR:\n"
				<< "This is unacceptable! I want to speak to the manager now." << '\n';
}

void	Harl::complain(std::string level)
{
	void			(Harl::*complain_ptr[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		levels[4] = {"debug", "info", "warning", "error"};
	int				i = -1;

	if (level != "debug" && level != "info" && level != "warning" && level != "error")
		return ;
	while (++i < 4)
	{
		if (levels[i] == level)
		{
			(this->*complain_ptr[i])();
			break ;
		}
	}
}
