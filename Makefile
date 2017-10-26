##
## EPITECH PROJECT, 2017
## makefile doop
## File description:
## doop makefile
##

SRC	=	infinadd.c \
		sub_fonction1.c \
		sub_fonction2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	lib $(NAME)

$(NAME):
	make -C lib/my/
	gcc -o $(NAME) $(SRC) -I./include -L ./lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
