/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:34:13 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:34:14 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	
	std::cout << "/////////TEST 1//////////\n";

	Span sp = Span(15);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printContainer();
	std::cout << "\n\n";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "\n\n";
	sp.printContainer();

	std::cout << "\n/////////TEST 2//////////\n";

	Span sp2(100);
	sp2.addManyNumbers(50);
	//sp2.printSortedContainer();
	std::cout << "\n\n";
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << "\n/////////TEST 3//////////\n";

	Span sp3(15000);
	sp3.addManyNumbers(12000);
	std::cout << "\n\n";
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return 0;
}


//1
//4294967293