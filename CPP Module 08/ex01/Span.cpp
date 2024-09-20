/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:34:27 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:34:28 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n)
{
	this->N = n;
}

Span::Span(Span &original)
{
	this->N = original.N;
}

Span &Span::operator=(const Span &original)
{
	this->N = original.N;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int num)
{

}

unsigned int Span::shortestSpan()
{

}

unsigned int Span::longestSpan()
{

}
