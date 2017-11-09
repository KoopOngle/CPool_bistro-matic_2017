NAME	=	window

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

ADD1	=	`pkg-config --libs --cflags gtk+-2.0`


all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(ADD1)
clean:
	rm -f $(OBJ)
fclean: clean
	rm *~
	rm -f $(NAME)
re:	fclean all
