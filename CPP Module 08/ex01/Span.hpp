/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:34:36 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:34:37 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>
#include <time.h>

class Span
{
	private:
		unsigned int N = 10000;
		std::vector<int> vec;

	public:
		Span(unsigned int n);
		Span(Span &original);
		Span &operator=(const Span &original);
		~Span();

		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void addManyNumbers(unsigned int quantity);
		void printConteiner();


		class VectorTooSmallException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class VectorFullException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# endif
