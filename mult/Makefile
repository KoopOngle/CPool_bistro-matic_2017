##
## EPITECH PROJECT, 2017
## makefile doop
## File description:
## doop makefile
##

SRC	=	*.c
OBJ	=	$(SRC:.c=.o)

NAME	=	infin_mult

all:	lib $(NAME)

$(NAME):
	make -C lib/my/
	gcc -g -o $(NAME) $(SRC) -lc_graph_prog -I./include -L ./lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
