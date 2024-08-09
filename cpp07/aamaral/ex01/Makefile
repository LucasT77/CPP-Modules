NAME = iter

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 #-g

RM = rm -rf

SRC = main.cpp

OBJ_FOLDER = objects

OBJ = $(SRC:%.cpp=$(OBJ_FOLDER)/%.o)

all: $(NAME)

$(NAME): $(OBJ) | $(OBJ_FOLDER)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_FOLDER)/%.o: %.cpp | $(OBJ_FOLDER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

${OBJ_FOLDER}:
	mkdir -p $(OBJ_FOLDER)

clean:
	$(RM) $(OBJ_FOLDER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
