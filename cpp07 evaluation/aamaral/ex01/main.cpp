// 42 header

#include "iter.hpp"
#include <iostream>

void	testIntArray( void )
{
	std::cout << "******** TEST INTEGER ARRAY ********" << std::endl;

	int		intArray[] = { -42 , -40, -2, 0, 2 , 40, 42 };	
	size_t	arraySize = 7;
	
	std::cout << "------ Using one function -----" << std::endl;
		::iter( intArray, arraySize, printElements<int> );
	std::cout << std::endl << "------ Using other function -----" << std::endl ;
	::iter( intArray, arraySize, printElementsPretty<int> );
	std::cout << std::endl;
}

void	testDoubleArray( void )
{
	std::cout << "******** TEST DOUBLE ARRAY ********" << std::endl;

	float		doubleArray[] = { -42.1 , -40.1, -2.1, 0.1, 2.1 , 40.1, 42.1 };	
	size_t	arraySize = 7;
	
	std::cout << "------ Using one function -----" << std::endl;
		::iter( doubleArray, arraySize, printElements<double> );
	std::cout << std::endl << "------ Using other function -----" << std::endl ;
	::iter( doubleArray, arraySize, printElementsPretty<double> );
	std::cout << std::endl;
}

void	testCharArray( void )
{
	std::cout << "******** TEST CHAR ARRAY ********" << std::endl;

	char		charArray[] = { '4' , '2', ' ', 'P', 'o' , 'r', 't', 'o' };	
	size_t	arraySize = 8;
	
	std::cout << "------ Using one function -----" << std::endl;
		::iter( charArray, arraySize, printElements<char> );
	std::cout << std::endl << "------ Using other function -----" << std::endl ;
	::iter( charArray, arraySize, printElementsPretty<char> );
	std::cout << std::endl;
}

void	testStringArray( void )
{
	std::cout << "******** TEST STRING ARRAY ********" << std::endl;

	std::string		stringArray[] = { "42" , "Porto", "is", "the", "best", "!" };	
	size_t	arraySize = 6;
	
	std::cout << "------ Using one function -----" << std::endl;
		::iter( stringArray, arraySize, printElements<std::string> );
	std::cout << std::endl << "------ Using other function -----" << std::endl ;
	::iter( stringArray, arraySize, printElementsPretty<std::string> );
	std::cout << std::endl;
}

int		main( void )
{
	std::cout << std::endl;
	testIntArray( );
	std::cout << std::endl;
	testDoubleArray( );
	std::cout << std::endl;
	testCharArray( );
	std::cout << std::endl;
	testStringArray( );
	std::cout << std::endl;
}

