/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:00:30 by luaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 15:00:31 by luaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define HighestGrade 1
#define LowestGrade 150

class Bureaucrat
{
	private:
		const std::string   Name = "Bureaucrat";
        int                 Grade = LowestGrade;

	public:
		Bureaucrat();
        Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &original);
		Bureaucrat &operator=(const Bureaucrat &original);
		~Bureaucrat();

        const std::string   getName(void);
        int                 getGrade(void);
        void                incrementGrade(void);
        void                decrementGrade(void);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &COUT, Bureaucrat const &bureaucrat);

# endif
