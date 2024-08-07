# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luaraujo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 20:09:23 by luaraujo          #+#    #+#              #
#    Updated: 2024/06/27 20:09:25 by luaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	megaphone

SOURCE		=	megaphone.cpp
OBJECT		=	$(SOURCE:.cpp=.o)

CXX 				=	c++
CXXFLAGS			=	-std=c++98 -Wall -Werror -Wextra
RM				=	rm -f


all:			$(NAME) 
$(NAME):		$(OBJECT)
						$(CXX) $(CXXFLAGS) $(OBJECT) -o megaphone
						echo "Mandatory done"

clean:
						$(RM) $(OBJECT)
						echo "Cleaned"

fclean:			clean
						$(RM) $(NAME)
						echo "Fully cleaned"

re:				fclean all