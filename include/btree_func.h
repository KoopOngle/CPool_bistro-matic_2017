/*
** EPITECH PROJECT, 2017
** btree_func.h
** File description:
** btree funcs
*/

#ifndef BTREE_FUNC_
#define BTREE_FUNC_
void btree_insert_data(btree_t **root, char op, char *value
		       , int last_was_par, char *opbase);
btree_t *btree_create_node(int value, char op);
void btree_concat_tree(btree_t **root, btree_t *node);
char *btree_t_val(btree_t *self, char **bases);
char *my_getnbrstrbase(char **str, char **bases);
btree_t *eval_expr(btree_t *node, char const *str, int sign, char **bases);
int is_in_base(char c, char *base);
#endif
