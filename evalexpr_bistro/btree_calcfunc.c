/*
** EPITECH PROJECT, 2017
** btree_calcfunc.c
** File description:
** calc fonc
*/

#include "my.h"
#include "btree.h"
#include <stdlib.h>

char *btree_t_val(btree_t *self, char *base, char *opbase)
{
	if (self->op == '\0')
		return (self->value);
	else {
		switch ((char)self->op) {
		case '+':
			return (inf_add(btree_t_val(self->left, base, opbase)
					,btree_t_val(self->right, base, opbase), base, opbase));
		case '-':
			return (inf_sub(btree_t_val(self->left, base, opbase)
                                        ,btree_t_val(self->right, base, opbase), base, opbase));
		case '/':
			return (inf_div(btree_t_val(self->left, base, opbase)
                                        ,btree_t_val(self->right, base, opbase), base, opbase));
		case '*':
			return (inf_mult(btree_t_val(self->left, base, opbase)
                                        ,btree_t_val(self->right, base, opbase), base, opbase));
		case '%':
			return (inf_mod(btree_t_val(self->left, base, opbase)
                                        ,btree_t_val(self->right, base, opbase), base, opbase));
		default :
			return (-84);
		}
	}
}
