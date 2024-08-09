# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 15:49:00 by luaraujo          #+#    #+#              #
#    Updated: 2024/07/24 15:49:10 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	FragTrap

SOURCE		=	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJECT		=	$(SOURCE:.cpp=.o)

CXX 				=	c++
CXXFLAGS			=	-std=c++98 -Wall -Werror -Wextra
RM				=	rm -f


all:			$(NAME) 
$(NAME):		$(OBJECT)
						$(CXX) $(CXXFLAGS) $(OBJECT) -o $(NAME)
						echo "Mandatory done"

clean:
						$(RM) $(OBJECT)
						echo "Cleaned"

fclean:			clean
						$(RM) $(NAME)
						echo "Fully cleaned"

re:				fclean all
