/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:32:32 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:32:34 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class easyFind : public std::exception
{
    public:
        const char *what() const throw()
        {
            return "Element not found in the container";
        }
};

template <typename T>
bool easyfind(T container, int num)
{
    if (std::find(container.begin(), container.end(), num) == container.end())
    {
        throw easyFind();
        return 0;
    }
    return 1;
}

#endif
