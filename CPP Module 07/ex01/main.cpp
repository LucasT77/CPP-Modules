/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:23:27 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:23:29 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter(tab, 5, print<const int> );
//   iter(tab2, 5, print<Awesome> );

//   return 0;
// }


int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	iter(arr, 10, print<int>);

	std::string str[] = {"Red", "Green", "Blue"};
	iter(str, 3, print<std::string>);
}
