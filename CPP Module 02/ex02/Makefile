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

NAME			=	fixed

SOURCE		=	main.cpp Fixed.cpp
OBJECT		=	$(SOURCE:.cpp=.o)

CC 				=	c++
CFLAGS			=	-std=c++98 -Wall -Werror -Wextra
RM				=	rm -f


all:			$(NAME) 
$(NAME):		$(OBJECT)
						$(CC) $(CFLAGS) $(OBJECT) -o fixed
						echo "Mandatory done"

clean:
						$(RM) $(OBJECT)
						echo "Cleaned"

fclean:			clean
						$(RM) $(NAME)
						echo "Fully cleaned"

re:				fclean all
