/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:25:44 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:25:45 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	/*Array<int>	a(3);
	Array<int>	b(3);

	for (size_t i = 0; i < a.size(); i += 1) {
		std::cout << "a[" << i << "] = " << a[i] << "\n";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		std::cout << "b[" << i << "] = " << b[i] << "\n";
	}
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	std::cout << std::endl;
	std::cout << "AFTER FILLING A WITH 1's" << std::endl;
	for (size_t i = 0; i < a.size(); i += 1) {
		std::cout << "a[" << i << "] = " << a[i] << "\n";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		std::cout << "b[" << i << "] = " << b[i] << "\n";
	}
	b = a;

	std::cout << "AFTER B = A" << std::endl;
	for (size_t i = 0; i < a.size(); i += 1) {
		std::cout << "a[" << i << "] = " << a[i] << "\n";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		std::cout << "b[" << i << "] = " << b[i] << "\n";
	}


    // Empty Array
    Array<int> empty;

	// OUT OF BOUNDS EXCEPTION
    try {
        std::cout << a[a.size() + 1] << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }*/

	Array<int> x(3);
	Array<int> y(x);
	Array<int> z;

	x[0] = 10;
	x[1] = 20;
	x[2] = 30;
	
	y[0] = 100;
	y[1] = 200;
	y[2] = 300;

	try
	{
		z[0] = 1000;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	z = x;

	std::cout << "x[0] = " << x[0] << "\n\n"; 

	std::cout << "x:\n";
	x.printAll();
	std::cout << std::endl;

	std::cout << "y:\n";
	y.printAll();
	std::cout << std::endl;

	std::cout << "z:\n";
	std::cout << "z.size() = " << z.size() << '\n';
	z.printAll();
	std::cout << std::endl;
}
