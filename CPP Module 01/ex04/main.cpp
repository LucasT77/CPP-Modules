/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:24:07 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/02 10:24:11 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	change_filename(char *filename)
{
	std::string	new_filename;
	int			i = -1;

	while (filename[++i])
	{
		if (filename[i] == '.')
			break ;
		new_filename += filename[i];
	}
	new_filename += ".replace";
	return (new_filename);
}

std::string	get_replaced_string(std::string str, std::string s1, std::string s2)
{
	std::string	newstr;
	int			pos = 0;
	std::size_t	found;

	while (true)
	{
		found = str.find(s1, pos);
		if (found == std::string::npos)
		{
			newstr += str.substr(pos);
			break ;
		}
		newstr += str.substr(pos, found - pos); //add substr of the original that should not be replaced
		pos = found + s1.length();
		newstr += s2; //add what should be replaced
	}
	return (newstr);
}

int	main(int argc, char **argv)
{
	std::string	filename, s1, s2, line;
	std::ifstream	original;
	std::ofstream	new_file;

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments. Try with 1 filename and 2 strings\n";
		return (0);
	}
	filename = argv[1];
    s1 = argv[2];
	s2 = argv[3];
	original.open(filename);
	filename = change_filename(argv[1]);
	new_file.open(filename);
	if (original.is_open() == false)
	{
		std::cout << "Invalid filename. Try again.\n";
		return (0);
	}
	if (new_file.is_open() == false)
	{
		std::cout << "Error creating new file. Try again.\n";
		return (0);
	}
	while (getline(original, line))
		new_file << get_replaced_string(line, s1, s2) << '\n';
	original.close();
	new_file.close();
}
