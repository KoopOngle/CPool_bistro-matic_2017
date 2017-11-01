/*
** EPITECH PROJECT, 2017
** btree_calcfunc.c
** File description:
** calc fonc
*/

#include "my.h"
#include "btree.h"
#include <stdlib.h>

int btree_t_val(btree_t *self)
{
	if (self->op == ' ')
		return (self->value);
	else {
		switch ((char)self->op) {
		case '+':
			return (self->left->val(self->left)
				+ self->right->val(self->right));
		case '-':
			return (self->left->val(self->left)
				- self->right->val(self->right));
		case '/':
			return (self->left->val(self->left)
				/ self->right->val(self->right));
		case '*':
			return (self->left->val(self->left)
				* self->right->val(self->right));
		case '%':
			return (self->left->val(self->left)
				% self->right->val(self->right));
		default :
			return (-84);
		}
	}
}
