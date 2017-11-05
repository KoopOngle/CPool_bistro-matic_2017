/*
** EPITECH PROJECT, 2017
** btree.h
** File description:
** btree.h
*/

#ifndef STACK_H_
#define STACK_H_
typedef struct stack
{
	struct stack *prev;
	btree_t *value;	
} stack_t;
#endif
