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
#include "Form.hpp"

#define HiGHESTGRADE 1
#define LOWESTGRADE 150

class Form;

class Bureaucrat
{
	private:
		const std::string   Name;
        int                 Grade;

	public:
		Bureaucrat();
        Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

        void		setName(std::string name);
        void		setGrade(int grade);
        std::string	getName(void) const;
        int			getGrade(void) const;
        void		incrementGrade(void);
        void		decrementGrade(void);

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

        //Additional function
        void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &COUT, Bureaucrat const &bureaucrat);

# endif
