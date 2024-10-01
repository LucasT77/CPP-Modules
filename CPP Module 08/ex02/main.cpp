/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:35:51 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:35:52 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main()
{
	std::cout << "///////////////TEST 1/////////////////" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	std::cout << std::endl << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "///////////////TEST 2/////////////////" << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite =  mstack.end();
	std::cout << "*it = " << *it << std::endl;
	++it;
	--it;
	std::cout << "After increment and decrement:\n";
	std::cout << "*it = " << *it << std::endl;
	
	std::cout << std::endl << std::endl;

	std::cout << "///////////////TEST 3/////////////////" << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl << std::endl;

	std::cout << "///////////////TEST 4/////////////////" << std::endl;

	MutantStack<int>::iterator it2;
	MutantStack<int>::iterator ite2;
	MutantStack<int>::iterator IT;
	it2 = mstack.begin();
	ite2 = mstack.end();

	for (IT = it2; IT < ite2; IT++)
		std::cout << *IT << std::endl;

	std::cout << "///////////////TEST 5/////////////////" << std::endl;
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);

	std::vector<int>::iterator it_vec;
	std::vector<int>::iterator ite_vec;
	std::vector<int>::iterator IT_vec;
	it_vec = vec.begin();
	ite_vec = vec.end();
	for (IT_vec = it_vec; IT_vec < ite_vec; IT_vec++)
		std::cout << *IT_vec << std::endl;
	
	return 0;
}
