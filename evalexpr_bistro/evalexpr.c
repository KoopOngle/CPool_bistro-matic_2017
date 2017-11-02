/*
** EPITECH PROJECT, 2017
** evalexpr.c
** File description:
** eval expr
*/

#include "my.h"
#include "btree.h"
#include "stack.h"
#include <stdlib.h>

int stack(stack_t **list, btree_t *node);
btree_t *get_without_unstack(stack_t *list);
btree_t *unstack(stack_t **list);
int getsize(stack_t *stk);
int is_empty(stack_t *stk);
void btree_insert_data(btree_t **root, char op, char *value, int last_was_par, char *opbase);
btree_t *btree_create_node(int value, char op);
int btree_t_val(btree_t *self);
void btree_concat_tree(btree_t **root, btree_t *node);
char *my_getnbrstrbase(char **str, char **bases);

int m_issign(char c)
{
	if (c == '\0' || c == '(')
		return (2);
	else if (c == '*' || c == '/' ||
		c == '%' || c == '+' || c == '-')                                   
		return (1);                                                    
	else                                                                    
		return (0);                                                     
}

char *get_strparentes(char **str, char* opbase)
{
	int i = 0;
	int par = 0;
	int parferm = 1;
	int ifirstpar;
	char *strdup = my_strdup(*str);

	while (strdup[i] != '\0' && parferm != 0) {
		if (strdup[i] == opbase[0] && par == 0) {
			par += 1;
			ifirstpar = i + 1;
		}
		if (strdup[i] == opbase[0] && par != 0)
			par += 1;
		if (strdup[i] == opbase[1]) {
			par -=1;
			parferm = (par == 1) ? 0 : 1;
		}
		i++;
	}
	*str = &str[0][i];
	if (parferm == 0) {
		strdup[i - 1] = '\0';
		return (&strdup[ifirstpar]);
	}
	return (*str);
}

btree_t *btree_sign(btree_t *node, int sign, char **bases)
{
	char *str;

	if (sign == 1) {
		str = malloc(sizeof(char) * 2 + 1);
		str[0] = bases[1][3];
		str[1] = bases[0][1];
		str[2] = '\0';
		btree_insert_data(&node, '\0', str, 0, bases[1]);
		btree_insert_data(&node, bases[1][4], 0, 0, bases[1]);
	}
	return (node);
}

btree_t *eval_expr(btree_t *node, char const *str, int sign, char **bases)
{
	int nb = 0;
	char *strdup = my_strdup(str);
	int last_was_par = 0;
	btree_t *sign_node = btree_sign(node, sign, bases);

	while (strdup[0] != '\0') {;
		if (strdup[0] == bases[1][0] || (strdup[0] == bases[1][3] && strdup[0 + 1] == bases[1][0])) {
			sign = (strdup[0] == bases[1][3]) ? 1 : 0;
			btree_concat_tree(&node, eval_expr(NULL , get_strparentes(&strdup, bases[1]), sign, bases));
			last_was_par = 1;
			nb = 1;
		}
		if (nb == 0 && strdup[0] != '\0') {
			btree_insert_data(&node, '\0', my_getnbrstrbase(&strdup, bases), last_was_par, bases[1]);
			last_was_par = 0;
			nb = 1;
		} else if (strdup[0] != '\0' && nb == 1){
			btree_insert_data(&node, strdup[0], 0, last_was_par, bases[1]);
			nb = 0;
			last_was_par = 0;
			strdup++;
		}
	}
	btree_concat_tree(&sign_node, node);
	return (sign_node);
}

