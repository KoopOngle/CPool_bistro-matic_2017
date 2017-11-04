##
## EPITECH PROJECT, 2017
## makefile lib
## File description:
## makefilelib
##

NAME	=	libmy.a

all:	$(NAME) cplib cph

$(NAME):
	gcc -c *.c
	ar rc $(NAME) *.o
cplib:
	cp $(NAME) ../

cph:
	cp my.h ../../include
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
