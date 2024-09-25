/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:36:26 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:36:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>

template <typename T>
class MutantStack
{
	private:
		std::stack<T> _stack;

	public:
		//Constructors
		MutantStack();
		MutantStack(MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		//Stack Original Methods
		T top();
		bool empty();
		unsigned int size();
		void push(T arg);
		void pop();
		void swap(MutantStack &other);
		void emplace(T arg);	
		
		class Iterator
		{

		};
};

///////Contructors & Destructor///////

template <typename T>
MutantStack<T>::MutantStack()
{
	
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack &other)
{
	*this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	this->_stack = other._stack;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() 
{
	
}

# endif
