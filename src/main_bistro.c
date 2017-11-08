/*
**EPITECHPROJECT,2017
**main_bistro.c
**Filedescription:
**mainbistro
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistro_matic.h"
#include "my.h"

static void check_base(char const *base);
static void check_ops(char const *ops);
static char *get_expr(unsigned size);
static void usage();

int main (int ac,char **av)
{
	unsigned int size;
	char *expr;
	if (ac != 4)
		usage();
	check_base(av[1]);
	check_ops(av[2]);
	size = my_getnbr(av[3]);
	expr = get_expr(size);
	my_putstr(start_bistro(av[1],av[2],expr,size));
	return(EXIT_SUCCESS);
}

static void usage()
{
	my_putstr("USAGE\n");
	my_putstr("\t\t./calc base operators size_read\n\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("\t\tbase\t\tall the symbols of the base\n");
	my_putstr("\t\toperators\tthe symbols for the parentheses ans the 5 operators\n");
	my_putstr("\t\tsize_read\tnumber of characters to be read\n");
	exit(EXIT_USAGE);
}

static void check_base(char const *b)
{
	if(my_strlen(b) < 2){
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_BASE);
	}
}

static char *get_expr(unsigned int size)
{
	char *expr;
	if(size <= 0){
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_SIZE_NEG);
	}
	expr=malloc(size + 1);
	if(expr == 0){
		my_putstr(ERROR_MSG);
		exit(EXIT_MALLOC);
	}
	if(read(0, expr, size) != size){
		my_putstr(ERROR_MSG);
		exit(EXIT_READ);
	}
	expr[size] = 0;
	return(expr);
}

static void check_ops(char const *ops)
{
	if (my_strlen(ops) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
	}
}
