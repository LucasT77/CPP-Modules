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

///Constructors & Destructor///

Span::Span(unsigned int n)
{
	this->N = n;
	vec.resize(N);
}

Span::Span(const Span &original)
{
	*this = original;
}

Span &Span::operator=(const Span &original)
{
	this->N = original.N;
	this->vec = original.vec;
	return (*this);
}

Span::~Span() {}

///Methods///

void Span::addNumber(int num)
{
	if (vec.size() + 1 <= vec.capacity())
		vec.push_back(num);
	else
		throw Span::VectorFullException();
}

void Span::addManyNumbers(unsigned int quantity)
{
	if (vec.size() + quantity <= vec.capacity())
		return throw Span::VectorFullException();
	srand(time(0));
	std::vector<int>::iterator it = vec.begin();
	for (unsigned int i = 1; i <= quantity; i++)
		*(it + i) = rand() % quantity; 
}

unsigned int Span::shortestSpan()
{
	unsigned int min;

	if (vec.size() <= 0)
		return throw Span::VectorTooSmallException(), NULL;
	std::vector<int>::iterator first = vec.begin();
	std::vector<int>::iterator last = vec.end();
	std::sort(first, last);
	min = *(first + 1) - *first;
	for (std::vector<int>::iterator it = (first + 1); it <= last; it++)
	{
		if ((*it + 1) - *it < min)
			min = (*it + 1) - *it;
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (vec.size() <= 0)
		return throw Span::VectorTooSmallException(), NULL;
	std::vector<int>::iterator first = vec.begin();
	std::vector<int>::iterator last = vec.end();
	std::sort(first, last);
	return (*last - *first);
}

void Span::printConteiner()
{
	for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
}


///Exceptions///

const char *Span::VectorTooSmallException::what() const throw()
{
    return "Vector has only 1 or less elements. Span cannot be found!\n";
}

const char *Span::VectorFullException::what() const throw()
{
    return "Vector is full. An element cannot be added!\n";
}
