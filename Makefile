##
## EPITECH PROJECT, 2017
## makefile doop
## File description:
## doop makefile
##

SRC	=	src/btree_calcfunc.c \
		src/btree_insert_data.c \
		src/btree_concat_tree.c \
		src/evalexpr.c \
		src/btree_create_node.c \
		src/inf_add_base.c \
		src/inf_mult_base.c \
		src/my_getnbrbase.c \
		src/main.c \
		src/main_bistro.c \
		src/modulo.c \
		src/function.c \
		src/function_2.c \
		src/function_3.c \
		src/function_4.c \
		src/function_5.c \
		src/divinf.c

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
