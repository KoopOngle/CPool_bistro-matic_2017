/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main
*/

#include "my.h"
#include "btree.h"
#include <stdlib.h>

void btree_insert_data(btree_t **root, char op, int value, int last_was_par, char **bases);
btree_t *btree_create_node(int value, char op);
char *btree_t_val(btree_t *self, char **bases);
btree_t *eval_expr(btree_t *node, char *str, int sign, char **bases);
void btree_apply_prefix(btree_t *root, int (*applyf)(char *, char));

int applyf(char *value, char op)
{
	printf("1 :%c\n", op);
	printf("2 :%s\n", value);
	return 0;
}
int	main(int argc, char **argv)
{
	btree_t *node;
	char *str = my_strdup(argv[1]);
        char **bases = malloc(sizeof(char *) * 2);
        bases[0] = my_strdup(argv[2]);
        bases[1] = my_strdup(argv[3]);
	node = eval_expr(NULL, str, 0, bases);
	//btree_apply_prefix(node, &applyf);
	/*btree_insert_data(&node, ' ', 2, btree_cmp_prio);
	btree_insert_data(&node, '*', 0, btree_cmp_prio);
	btree_insert_data(&node, ' ', 2, btree_cmp_prio);
	btree_insert_data(&node, '+', 0, btree_cmp_prio);
	btree_insert_data(&node, ' ', 4, btree_cmp_prio);
	btree_insert_data(&node, '-', 0, btree_cmp_prio);
	btree_insert_data(&node, ' ', 16, btree_cmp_prio);
	btree_insert_data(&node, '/', 0, btree_cmp_prio);
	btree_insert_data(&node, ' ', 3, btree_cmp_prio);
	btree_insert_data(&node, '+', 0, btree_cmp_prio);
	btree_insert_data(&node, ' ', 0, btree_cmp_prio);*/
        /*btree_t *node1 = btree_create_node(-12, ' ', &btree_t_val);
        btree_t *node2 = btree_create_node(NULL, '-', &btree_t_val);
	node0->left = node1;
	node0->right = node2;
	btree_t *node3 = btree_create_node(42, ' ', &btree_t_val);
	btree_t *node4 = btree_create_node(NULL, '*', &btree_t_val);
	node2->left = node3;
	node2->right = node4;
	btree_t *node5 = btree_create_node(4, ' ', &btree_t_val);
	btree_t *node6 = btree_create_node(NULL, '+', &btree_t_val);
	node4->left = node5;
	node4->right = node6;
	btree_t *node7 = btree_create_node(4, ' ', &btree_t_val);
	btree_t *node8 = btree_create_node(3, ' ', &btree_t_val);
	node6->left = node7;
	node6->right = node8;*/
	my_putstr(btree_t_val(node, bases));
	return (0);
}
