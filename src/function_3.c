/*
** EPITECH PROJECT, 2017
** function3.c
** File description:
** function3
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "inf_add.h"

int in_to_base_a(char *base, char c)
{
	for(int i = 0; base[i] != '\0'; i++)
		if (base[i] == c)
			return (i);
}

int is_in_to_base(char *base, char c)
{
	for(int i = 0; base[i] != '\0'; i++)
		if (base[i] == c)
			return (1);
}

char *add_minus_a(char *str, char *opbase)
{
	char *res = malloc(sizeof(char) * (my_strlen(str)) + 2);

	res = my_revstr(str);
	res[my_strlen(str)] = opbase[3];
	res[my_strlen(str) + 1] = '\0';
	return (my_revstr(res));
}

char *k_clear_za(char *str, char *base, char *opbase)
{
	char *tmp = my_strdup(str);

	if (tmp[0] == opbase[3])
		tmp++;
	while (tmp[0] == base[0] && tmp[1] != '\0')
		tmp++;
	return (tmp);
}
