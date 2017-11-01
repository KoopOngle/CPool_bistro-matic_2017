/*
** EPITECH PROJECT, 2017
** btree_create_node.c
** File description:
** btree create node
*/

#include <stdlib.h>
#include "btree.h"

btree_t *btree_create_node(char *value, char op, int (*valfunc)(btree_t *))
{
	btree_t *node;

	node = malloc(sizeof(btree_t));
	node->value = value;
	node->op = op;
	node->left = NULL;
	node->right = NULL;
	node->val = valfunc;
	return (node);
}
