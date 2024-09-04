/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <luaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:25:24 by luaraujo          #+#    #+#             */
/*   Updated: 2024/09/03 17:27:48 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int r_num;

	srand(time(0));
    r_num = rand() % 3;
	switch (r_num)
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	case 2:
		return new C();
		break;
	default:
		return new A();
		break;
	}
}

void print_id(char id, char type)
{
	if (id == 0)
		std::cout << "Error: Unable to identify object from Base" << type << std::endl;
	else
		std::cout << "The object from Base" << type << " belongs to the class: " << id << std::endl;
} 

void identify(Base* p)
{
	char id;

	if (dynamic_cast<A *>(p))
		id = 'A';
	else if (dynamic_cast<B *>(p))
		id = 'B';
	else if (dynamic_cast<C *>(p))
		id = 'C';
	else
		id = 0;
	print_id(id, '*');
}

void identify(Base& p)
{
	char id;

	try
	{
		dynamic_cast<A &>(p);
		id = 'A';
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B &>(p);
			id = 'B';
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C &>(p);
				id = 'C';
			}
			catch(const std::exception& e)
			{
				id = 0;
			}
			
		}
		
	}
	print_id(id, '&');
}
