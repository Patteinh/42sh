##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

NAME	=	42sh

CFLAGS	= 	-I ./include/ -W -Wall -Wextra -I $(LIB)include/

LFLAGS 	= 	-L $(LIB) -lmy

DIR		=	./src/

LIB		=	./lib/

CMD		=	src/my_cmd/

SRC		=	$(DIR)main.c		\
			$(DIR)tools.c		\
			$(DIR)choice_cmd.c	\
			$(DIR)bin_cmd.c		\
			$(CMD)cd.c			\
			$(CMD)env.c			\
			$(CMD)exit.c		\
			$(CMD)my_cmd.c		\
			$(CMD)setenv.c		\
			$(CMD)unsetenv.c	\

OBJ		=	$(SRC:.c=.o)

RMO		=	$(RM) $(OBJ)

all: $(NAME)
	@echo "Build ok!"

build_lib :
	$(MAKE) -C $(LIB)

$(NAME): build_lib $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -o $(NAME)

debug: MAKE += -E CFLAGS+=-g3
debug: CFLAGS += -g3
debug: $(NAME)
	@echo "Build ok!"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIB) -s
	@echo "Clean ok!"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIB) -s
	@echo "Fclean ok!"

re: fclean all

.PHONY: all build_lib debug clean fclean re
