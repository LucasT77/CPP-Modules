// 42 header

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
//#define MAX_VAL 10


template <typename T>
void	printArrayPointer(const T& array)
{
	std::cout << "[" ;
	for ( size_t i = 0; i < MAX_VAL; ++i )
		std::cout << " " << array[i] << ",";
	std::cout << "]";	
}

int		testIntraMain( void )
{
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

   	std::cout << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int		testIntArray( void )
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 10;
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "***** Arrays created *****" << std::endl;
	std::cout << "--- Numbers array stack created ---" << std::endl;
	std::cout << numbers << std::endl;
	std::cout << "--- Mirror array heap created ---" << std::endl;
	printArrayPointer(mirror);
	std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "--- Tmp array assignment created ---" << std::endl;
		std::cout << tmp << std::endl;
		std::cout << "--- Test array copy created ---" << std::endl;
		std::cout << test << std::endl;
		std::cout << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
	if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "Mirror and Numbers arrays saved the same values" << std::endl << std::endl;
	try
	{
		std::cout << "--- Testing numbers[-2] ---" << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "--- Testing numbers[MAX_VAL] ---" << std::endl;
		numbers[MAX_VAL] = 0;
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout << std::endl;
	std::cout << "--- Testing new values on Numbers ---" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 10;
    }
	std::cout << numbers << std::endl << std::endl;

	delete [] mirror;//
	return 0;
}

int		testCharArray( void )
{
	Array<char> letters(MAX_VAL);
	char* mirror = new char[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 26;
		letters[i] = value + 65;
		mirror[i] = value + 65;
	}

	std::cout << "***** Arrays created *****" << std::endl;
	std::cout << "--- Letters array stack created ---" << std::endl;
	std::cout << letters << std::endl;
	std::cout << "--- Mirror array heap created ---" << std::endl;
	printArrayPointer(mirror);
	std::cout << std::endl;
    //SCOPE
    {
        Array<char> tmp = letters;
        Array<char> test(tmp);
        std::cout << "--- Tmp array assignment created ---" << std::endl;
		std::cout << tmp << std::endl;
		std::cout << "--- Test array copy created ---" << std::endl;
		std::cout << test << std::endl;
		std::cout << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
	if (mirror[i] != letters[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "Mirror and Letters arrays saved the same values" << std::endl << std::endl;
	try
	{
		std::cout << "--- Testing letters[-2] ---" << std::endl;
		letters[-2] = '0';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "--- Testing letters[MAX_VAL] ---" << std::endl;
		letters[MAX_VAL] = '0';
	}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout << std::endl;
	std::cout << "--- Testing new values on Letters ---" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        letters[i] = rand() % 26 + 65;
    }
	std::cout << letters << std::endl << std::endl;
	delete [] mirror;//
	return 0;
}

void	testEmptyArray( void )
{
	Array<int> numbers;
	std::cout << numbers << std::endl;	
}

int		main( void )
{
	std::cout << "******** TEST INTRA MAIN ********" << std::endl << std::endl;
	testIntraMain();
/*
	std::cout << "******** TEST EMPTY ARRAY ********" << std::endl << std::endl;
	testEmptyArray();

	std::cout << "******** TEST INT ARRAY ********" << std::endl << std::endl;
	testIntArray();
	
	std::cout << "******** TEST CHAR ARRAY ********" << std::endl << std::endl;
	testCharArray();
*/
}
