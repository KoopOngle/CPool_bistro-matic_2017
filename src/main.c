/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main
*/

#include "my.h"
#include "btree.h"
#include <stdlib.h>
#include "btree_func.h"

void check_parentheses(char const *str, char *opbase)
{
	int openpar = 0;
	int closepar = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		openpar += (str[i] == opbase[0]) ? 1 : 0;
		closepar += (str[i] == opbase[1]) ? 1 : 0;
		i++;
	}
	if (openpar != closepar) {
		my_putstr("syntax error");
		exit(84);
	}
}

void check_is_in(char const *str, char *base, char *opbase)
{
	int i = 0;
	int k = 0;

	while (str[i] != '\0') {
		if (is_in_base(str[i], base) != 1
		    && is_in_base(str[i], opbase) != 1) {
			my_putstr("syntax error");
			exit(84);
		}
		i++;
	}
}

char *start_bistro(char	const *base, char const *ops,
                   char	const *expr, unsigned int size)
{
	char **bases = malloc(sizeof(char *) *2);
	char *str = my_strdup(expr);
	btree_t *node;

	bases[0] = my_strdup(base);
	bases[1] = my_strdup(ops);
	if (size <= 0) {
		my_putstr("syntax error");
		exit(84);
	}
	check_is_in(expr, bases[0], bases[1]);
	check_parentheses(expr, bases[1]);
	node = eval_expr(NULL, str, 0, bases);
	return (btree_t_val(node, bases));
}
