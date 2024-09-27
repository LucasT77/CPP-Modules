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
#include <stack>

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

		//Iterator Methods
		T *begin();
		T *end();	
		
		struct iterator
		{
			private:
				T* it_ptr;

			public:

				iterator(T* ptr);

				iterator &operator=(T *ptr);
				bool operator==(MutantStack<T>::iterator other);
				bool operator!=(MutantStack<T>::iterator other);
				iterator &operator++(void);
				iterator &operator--(void);
				iterator operator++(T);
				iterator operator--(T);
				T operator*(void);
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

///////Stack Original Methods///////

template <typename T>
T				MutantStack<T>::top() {return _stack.top();}
template <typename T>
bool 			MutantStack<T>::empty() {return _stack.empty();}
template <typename T>
unsigned int	MutantStack<T>::size() {return _stack.size();}
template <typename T>
void			MutantStack<T>::push(T arg) {_stack.push(arg);}
template <typename T>
void			MutantStack<T>::pop() {_stack.pop();}
template <typename T>
void			MutantStack<T>::swap(MutantStack &other) {this->_stack.swap(other._stack);}
template <typename T>
void			MutantStack<T>::emplace(T arg) {_stack.emplace(arg);}

///////Iterator Methods///////

template <typename T>
T	*MutantStack<T>::begin() {return _stack;}

template <typename T>
T	*MutantStack<T>::end() {return _stack + (_stack.size() - 1);}

///////Iterator Constructor///////

template <typename T>
MutantStack<T>::iterator::iterator(T* ptr) : it_ptr(ptr)
{

}

///////Iterator Overload///////

template <typename T>
MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(T *ptr)
{
	this->it_ptr = ptr;
	return (*this);
}

template <typename T>
bool MutantStack<T>::iterator::operator==(MutantStack<T>::iterator other)
{
	return (this->it_ptr == other.it_ptr);
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(MutantStack<T>::iterator other)
{
	return (this->it_ptr != other.it_ptr);
}

template <typename T>
MutantStack<T>::iterator &MutantStack<T>::iterator::operator++(void)
{
	this->it_ptr++;
	return (*this);
}

template <typename T>
MutantStack<T>::iterator &MutantStack<T>::iterator::operator--(void)
{
	this->it_ptr--;
	return (*this);
}

template <typename T>
MutantStack<T>::iterator MutantStack<T>::iterator::operator++(T)
{
	MutantStack<T>::iterator tmp = *this;
	++(*this);
	return (tmp);
}

template <typename T>
MutantStack<T>::iterator MutantStack<T>::iterator::operator--(T)
{
	MutantStack<T>::iterator tmp = *this;
	--(*this);
	return (tmp);
}

template <typename T>
T MutantStack<T>::iterator::operator*(void)
{
	return *it_ptr;
}

#endif
