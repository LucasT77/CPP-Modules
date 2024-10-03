/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:47:11 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:47:12 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(RPN &original);
		RPN &operator=(const RPN &original);
		~RPN();

		static bool calculate(const std::string str, int *result);

		// class badInput : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();
		// };
};

# endif
