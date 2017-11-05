##
## EPITECH PROJECT, 2017
## makefile doop
## File description:
## doop makefile
##

SRC	=	btree_calcfunc.c \
		btree_insert_data.c \
		btree_concat_tree.c \
		evalexpr.c \
		btree_create_node.c \
		inf_add_base.c \
		inf_mult_base.c \
		my_getnbrbase.c \
		main.c \
		main_bistro.c \
		modulo.c \
		inf_div.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -o $(NAME) $(SRC) -I ./include/ -L lib/my/ -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my 

re:	fclean all
