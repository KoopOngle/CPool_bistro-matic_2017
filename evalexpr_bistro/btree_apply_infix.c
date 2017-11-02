/*
** EPITECH PROJECT, 2017
** btree_apply_infix
** File description:
** apply infix
*/

#include "btree.h"
#include <stdlib.h>

void btree_apply_prefix(btree_t *root, int (*applyf)(char *, char))
{
	(*applyf)(root->value, root->op);
	if (root->left != NULL)
		btree_apply_prefix(root->left, applyf);
	if (root->right != NULL)
		btree_apply_prefix(root->right, applyf);
}
