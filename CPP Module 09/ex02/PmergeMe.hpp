/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:49:26 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:49:27 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

#define MICROSECOND 1000000

class PmergeMe
{	
	public:
		PmergeMe();
		PmergeMe(PmergeMe &original);
		PmergeMe &operator=(const PmergeMe &original);
		~PmergeMe();

		static void sort(int argc, char **argv);
};

# endif
