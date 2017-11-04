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
		btree_apply_infix.c

OBJ	=	$(SRC:.c=.o)

NAME	=	testEval

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -I ./include/ -L ../lib/my/ -lmy


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
