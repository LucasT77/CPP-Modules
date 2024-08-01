DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Basic definitions

NAME		=	animal
SRC_DIR		=	./
OBJ_DIR		=	obj/
CC			=	c++
RM			=	rm -f
CFLAGS		=	-std=c++98 -Wall -Werror -Wextra -g
ARGS		=	
# Libs are always after objects in the compilation
# If you put them before, it won't compile

#Source files

SRC_FILES	=	main Animal Dog Cat WrongAnimal WrongCat Brain
B_SRC_FILES	=	

SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_SRCS			=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(B_SRC_FILES)))
B_OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(B_SRC_FILES)))
OBJ_FILES		=	.cache_exists

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Animal fully compiled!$(DEF_COLOR)"

debug:	override CFLAGS := -fsanitize=thread -static-libasan $(CFLAGS)
debug:	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Animal fully compiled in debug mode!$(DEF_COLOR)"
# if stack traces look weird, add: -fno-omit-frame-pointer -O1
# statically link with libasan with :-static-libasan or -static-libsan
# data race detector, cannot be used with address: -fsanitize=thread
# set ASLR off: setarch `uname -m` -R ./prog
# undefined behaviour dectector: -fsanitize=undefined

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp | $(OBJ_FILES)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FILES):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(OBJ_FILES)
	@echo "$(BLUE)Animal object files cleaned!$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(CYAN)Animal file cleaned!$(DEF_COLOR)"

re:	fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for Animal!$(DEF_COLOR)"

rebug:	fclean debug
	@echo "$(GREEN)Cleaned and rebuilt everything for Animal in debug mode!$(DEF_COLOR)"

run:	./animal
	./animal $(ARGS)

test:	./animal
	./animal

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) include -c $(SRCS)
#	gcc -nostartfiles -shared -o libprintf.so $(OBJS)

.PHONY:	all clean fclean re debug rebug run test
