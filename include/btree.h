/*
** EPITECH PROJECT, 2017
** btree.h
** File description:
** btree.h
*/

#ifndef BTREE_H_
#define BTREE_H_
typedef struct btree
{
	struct btree *left;
	struct btree *right;
	char *value;
	char op;

	int (*val)(struct btree *);
} btree_t;
#endif
