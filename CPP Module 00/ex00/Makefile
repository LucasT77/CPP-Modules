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

CC 				=	c++
CFLAGS			=	-std=c++98 -Wall -Werror -Wextra
RM				=	rm -f


all:			$(NAME) 
$(NAME):		$(OBJECT)
						$(CC) $(CFLAGS) $(OBJECT) -o megaphone
						echo "Mandatory done"

clean:
						$(RM) $(OBJECT)
						echo "Cleaned"

fclean:			clean
						$(RM) $(NAME)
						echo "Fully cleaned"

re:				fclean all