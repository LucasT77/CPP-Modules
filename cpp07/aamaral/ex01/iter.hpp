// 42 header

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template < typename T >
void	printElementsPretty( const T& data )
{
	std::cout << "[" << data << "] " ;
}

template < typename T >
void	printElements( const T& data )
{
	std::cout << data  << "  ";
}

template < typename T, typename F >
void	iter( T array[], size_t size, F func )
{
	for ( size_t i = 0; i < size; i++ )
		func( array[ i ] );
}

#endif
