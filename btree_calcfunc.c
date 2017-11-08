/*
** EPITECH PROJECT, 2017
** btree_calcfunc.c
** File description:
** calc fonc
*/

#include "my.h"
#include "btree.h"
#include <stdlib.h>
#include "inf_add.h"
#include "btree_func.h"

static char *val_second_if(btree_t *self, char **bases)
{
	char op = self->op;

	if (op == bases[1][6])
		return (inf_mod(btree_t_val(self->left, bases)
				,btree_t_val(self->right, bases), bases));
	if (op == bases[1][5])
		return (inf_div(btree_t_val(self->left, bases)
				,btree_t_val(self->right, bases), bases));
	my_putstr("Error Operators");
	exit(84);
}

static char *val_first_if(btree_t *self, char **bases)
{
	char op = self->op;

	if (op == bases[1][2])
		return (inf_add(btree_t_val(self->left, bases)
				,btree_t_val(self->right, bases), bases));
	if (op == bases[1][3])
		return (inf_sub(btree_t_val(self->left, bases)
				,btree_t_val(self->right, bases), bases));
	if (op == bases[1][4])
		return (inf_mult(btree_t_val(self->left, bases)
				 ,btree_t_val(self->right, bases)
				 , bases[0], bases[1]));
	return (val_second_if(self, bases));
}

char *btree_t_val(btree_t *self, char **bases)
{
	if (self->op == '\0') {
		return (self->value);
	}
	return (val_first_if(self, bases));
}

