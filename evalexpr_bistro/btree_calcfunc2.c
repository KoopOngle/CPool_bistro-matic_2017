/*
** EPITECH PROJECT, 2017
** btree_calcfunc.c
** File description:
** calc fonc
*/

#include "my.h"
#include "btree.h"
#include <stdlib.h>

int btree_t_val(btree_t *self, char *base, char *opbase)
{
	if (self->op == '\0')
		return (self->value);
	else {
		switch ((char)self->op) {
		case '+':
			return (btree_t_val(self->left, base, opbase)
				+ btree_t_val(self->right, base, opbase));
		case '-':
			return (btree_t_val(self->left, base, opbase)
				- btree_t_val(self->right, base, opbase));
		case '/':
			return (btree_t_val(self->left, base, opbase)
				/ btree_t_val(self->right, base, opbase));
		case '*':
			return (btree_t_val(self->left, base, opbase)
				* btree_t_val(self->right, base, opbase));
		case '%':
			return (btree_t_val(self->left, base, opbase)
				% btree_t_val(self->right, base, opbase));
		default :
			return (-84);
		}
	}
}
