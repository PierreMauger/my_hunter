##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

SRC 		=	hunter.c			\
				entity.c			\
				entity1.c			\
				game.c				\
				data.c				\
				my_rev_list.c		\

SRC_MAIN	=	main.c				\

NAME 		=	my_hunter

OBJ 		=	$(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

CFLAGS		=	-I include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS_DEBUG=	-Wall -Wextra -W -g

$(NAME):	$(OBJ) $(OBJ_MAIN)
	@(gcc $(OBJ) $(OBJ_MAIN) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

clean:
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@(rm -f $(NAME)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null

re:	fclean all

debug:
	gcc $(OBJ) $(OBJ_MAIN) -o $(NAME) $(CFLAGS) $(CFLAGS_DEBUG)
