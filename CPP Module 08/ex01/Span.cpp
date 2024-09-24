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
	vec.reserve(N);
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
	// std::cout << "vec.capacity = " << vec.capacity() << std::endl;
	// std::cout << "vec.size() = " << vec.size() << std::endl;
	// std::cout << "vec.size + quantity = " << vec.size() + quantity << std::endl;
	srand(time(0));
	try
	{
		for (unsigned int i = 1; i <= quantity; i++)
			this->addNumber(rand()); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int Span::shortestSpan()
{
	int min;
	std::vector<int> temp = vec;

	if (vec.size() <= 0)
		return throw Span::VectorTooSmallException(), NULL;
	std::vector<int>::iterator first = temp.begin();
	std::vector<int>::iterator last = temp.end();
	std::sort(first, last);
	min = *(first + 1) - *first;
	for (std::vector<int>::iterator it = (first + 1); it < last - 1; it++)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return min;
}

unsigned int Span::longestSpan()
{
	std::vector<int> temp = vec;

	if (vec.size() <= 0)
		return throw Span::VectorTooSmallException(), NULL;
	std::vector<int>::iterator first = temp.begin();
	std::vector<int>::iterator last = temp.end();
	std::sort(first, last);
	return (*(last - 1) - *first);
}

void Span::printContainer()
{
	for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
}

void Span::printSortedContainer()
{
	std::vector<int> temp = vec;
	std::vector<int>::iterator first = temp.begin();
	std::vector<int>::iterator last = temp.end();
	std::sort(first, last);
	for (unsigned int i = 0; i < temp.size(); i++)
        std::cout << temp[i] << std::endl;
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
