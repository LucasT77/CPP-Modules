/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:49:18 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:49:21 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

///////CONSTRUCTORS///////

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe &other) {(void)other;}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) 
{
	(void)other;
	return *this;
}
PmergeMe::~PmergeMe() {}

///////FUNCTIONS///////


bool	arg_to_container(int argc, char **argv, std::vector<unsigned int> &vec, std::list<unsigned int> &lst)
{
	std::string buf;
	unsigned int num;
	for (int i = 0; i < argc; i++)
	{
		buf = argv[i];
		if (buf.find_first_not_of("0123456789") != std::string::npos)
			return std::cout<< "Error", 0;
		num = atoi(argv[i]);
		vec.push_back(num);
		lst.push_back(num);
	}
	return 1;
}

void printVector(std::vector<unsigned int> &vec)
{
	std::vector<unsigned int>::iterator it = vec.begin();
	std::vector<unsigned int>::iterator ite = vec.end();
	while (it != ite)
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
}

void printList(std::list<unsigned int> &lst)
{
	std::list<unsigned int>::iterator it = lst.begin();
	std::list<unsigned int>::iterator ite = lst.end();

	while (it != ite)
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
}

std::vector<unsigned int>	mergeVector(std::vector<unsigned int> &left, std::vector<unsigned int> &right)
{
	std::vector<unsigned int> result;

	while (!left.empty() && !right.empty())
	{
		if (left.front() < right.front())
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}

	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}

	return result;
}

void	sortVector(std::vector<unsigned int> &vec)
{
	if (vec.size() <= 1)
		return ;
	std::vector<unsigned int> left;
	std::vector<unsigned int> right;
	for (std::size_t i = 0; i < (vec.size() / 2); i++)
		left.push_back(vec[i]);
	for (std::size_t i = (vec.size() / 2); i < vec.size(); i++)
		right.push_back(vec[i]);
	
	sortVector(left);
	sortVector(right);
	vec = mergeVector(left, right);
}

std::list<unsigned int> mergeList(std::list<unsigned int> left, std::list<unsigned int> right)
{
	std::list<unsigned int> result;

	while (!left.empty() && !right.empty())
	{
		if (left.front() < right.front())
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}

	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	
	return result;
}

void	sortList(std::list<unsigned int> &lst)
{
	if (lst.size() <= 1)
		return ;
	std::list<unsigned int> left;
	std::list<unsigned int> right;
	std::list<unsigned int>::iterator it_init = lst.begin();
	std::list<unsigned int>::iterator it_end = lst.end();
	it_end--;
	for (std::size_t i = 0; i < (lst.size() / 2); i++)
	{
		left.push_back(*it_init);
		it_init++;
		right.push_back(*it_end);
		it_end--;
	}
	if (it_init == it_end)
		left.push_back(*it_init);
	sortList(left);
	sortList(right);
	lst = mergeList(left, right);
}

///////METHOD///////

void	PmergeMe::sort(int argc, char **argv)
{
	std::vector<unsigned int> vec;
	std::list<unsigned int> lst;
	double time_vec;
	double time_lst = 0;

	if (!arg_to_container(argc, argv, vec, lst))
		return ;
	std::clock_t start_vec = std::clock();
	sortVector(vec);
	time_vec = static_cast<double>(std::clock() - start_vec) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	std::clock_t start_lst = std::clock();
	sortList(lst);
	time_lst = static_cast<double>(std::clock() - start_lst) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	// std::cout << "Sorted list: ";
	// printList(lst);

	std::cout << "Before:	";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl << "After:	";
	printVector(vec);
	std::cout	<< std::endl << "Time to process a range of "
				<< argc << " elements with std::vector : " << time_vec << " μs\n"
				<< "Time to process a range of "
				<< argc << " elements with std::list : " << time_lst << " μs\n";
}
