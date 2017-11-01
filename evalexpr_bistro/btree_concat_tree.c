/*
** EPITECH PROJECT, 2017
** btree_concat_tree.c
** File description:
** concat tree
*/

#include "my.h"
#include "btree.h"
#include <stdlib.h>

void btree_concat_tree(btree_t **root, btree_t *node)
{

        if (root != NULL && *root != NULL) {
                btree_concat_tree(&(*root)->right, node);
        } else if (root != NULL && *root == NULL) {
                *root = node;
        }
}
