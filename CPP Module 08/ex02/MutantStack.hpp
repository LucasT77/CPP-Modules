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
#include <cstddef>  // For std::ptrdiff_t

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
		
		class iterator
		{
			private:
				T* it_ptr;

			public:
				//Constructors
				iterator();
				iterator(T* ptr);

				//Operator overload
				iterator &operator=(T *ptr);

				T& operator*(void) const {return *it_ptr;}
				T* operator->(void) const {return it_ptr;}
				T& operator[](std::ptrdiff_t n) const {return *(it_ptr + n);}

				iterator &operator++(void);
				iterator operator++(T);
				iterator &operator--(void);
				iterator operator--(T);
				iterator &operator+=(std::ptrdiff_t n);
				iterator &operator-=(std::ptrdiff_t n);

				bool operator!=(MutantStack<T>::iterator other);
				bool operator<(MutantStack<T>::iterator other);
				bool operator>(MutantStack<T>::iterator other);
				bool operator<=(MutantStack<T>::iterator other);
				bool operator>=(MutantStack<T>::iterator other);
		};

		class StackOutOfRange: public std::exception
		{
			public:
				virtual const char* what() const throw();
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
T	*MutantStack<T>::begin() {return &_stack.top() - (_stack.size() - 1);}

template <typename T>
T	*MutantStack<T>::end() {return &_stack.top() + 1;}

///////Iterator Constructors///////

template <typename T>
MutantStack<T>::iterator::iterator() : it_ptr(NULL) {}

template <typename T>
MutantStack<T>::iterator::iterator(T* ptr) : it_ptr(ptr) {}

///////Iterator Overload///////

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(T *ptr)
{
	this->it_ptr = ptr;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++(void)
{
	this->it_ptr++;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(T)
{
	MutantStack<T>::iterator tmp = *this;
	++it_ptr;
	return (tmp);
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--(void)
{
	this->it_ptr--;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(T)
{
	MutantStack<T>::iterator tmp = *this;
	--it_ptr;
	return (tmp);
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator+=(std::ptrdiff_t n)
{
	it_ptr += n;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator-=(std::ptrdiff_t n)
{
	it_ptr -= n;
	return *this;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(MutantStack<T>::iterator other)
{
	return this->it_ptr != other.it_ptr;
}

template <typename T>
bool MutantStack<T>::iterator::operator<(MutantStack<T>::iterator other)
{
	return this->it_ptr < other.it_ptr;
}

template <typename T>
bool MutantStack<T>::iterator::operator>(MutantStack<T>::iterator other)
{
	return this->it_ptr > other.it_ptr;
}

template <typename T>
bool MutantStack<T>::iterator::operator<=(MutantStack<T>::iterator other)
{
	return this->it_ptr <= other.it_ptr;
}

template <typename T>
bool MutantStack<T>::iterator::operator>=(MutantStack<T>::iterator other)
{
	return this->it_ptr >= other.it_ptr;
}

#endif
