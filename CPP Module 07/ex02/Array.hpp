/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:26:22 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:26:24 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T *arr;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array &other);
		Array &operator=(const Array &other);
		~Array();

		class IndexOutOfBounds : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		unsigned int size() const;
		void printAll();
		T &operator[](unsigned int index);
};

///////Contructors///////

template <typename T>
Array<T>::Array()
{
	arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	arr = new T[_size];
}

template <typename T>
Array<T>::Array(Array &other)
{
	*this = other;
}

///////Destructors///////

template <typename T>
Array<T>::~Array() 
{
	delete [] arr;
}

///////Operator overloading///////

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	delete [] arr;
	this->_size = other.size();
	arr = new T[_size];
	for (unsigned int i = 0; i < other._size; i++)
		arr[i] = other.arr[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw Array<T>::IndexOutOfBounds();
	return arr[index];
}

///////Exception///////

template <typename T>
const char *Array<T>::IndexOutOfBounds::what() const throw()
{
    return "Index out of bounds!\n";
}

///////Methods///////

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
void Array<T>::printAll()
{
	for(unsigned int i = 0; i < _size; i++)
		std::cout << "[" << i << "]" << arr[i] << std::endl;
}

#endif
