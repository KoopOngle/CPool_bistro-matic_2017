/*
** EPITECH PROJECT, 2017
** btree_insert_data.c
** File description:
** insert data in btree
*/

#include "btree.h"
#include <stdlib.h>
#include "btree_func.h"

static int cmp_prio(char op1, char op2, char *opbase)
{
	if ((op1 == opbase[3] || op1 == opbase[2])
		&& (op2 == opbase[4] || op2 == opbase[5] || op2 == opbase[6]))
		return (2);
	return (1);
}

static int btree_cmp_prio(char op1, char op2, int last_was_par, char *opbase)
{
	if (op1 == '\0' || last_was_par == 1) {
		return (0);
	}
	return(cmp_prio(op1, op2, opbase));
}



void btree_insert_data(btree_t **root, char op, char *value
			, int last_was_par, char *opbase)
{
	int comp;
	btree_t *new_node;

	if (root != NULL && *root != NULL) {
		comp = btree_cmp_prio((*root)->op, op, last_was_par, opbase);
		if (op == '\0') {
			btree_insert_data(&(*root)->right, op
					  , value, last_was_par, opbase);
		}
		else if (comp == 1 || comp == 0) {
			new_node = btree_create_node(value, op);
			new_node->left = *root;
			*root = new_node;
		} else {
			new_node = btree_create_node(value, op);
			new_node->left = (*root)->right;
			(*root)->right = new_node;
		}
	} else if (root != NULL && *root == NULL) {
		*root = btree_create_node(value, op);
	}
}
