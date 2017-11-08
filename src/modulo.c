/*
** EPITECH PROJECT, 2017
** modulo.c
** File description:
** modulo infini
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "inf_add.h"

char *inf_mod(char *a1, char *a2, char **bases)
{
	int i = 0;
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	char *res = malloc(sizeof(char) * (a1s) + 4);
	char *nb3 = malloc(sizeof(char) * (a1s) + 4);
	char *tmp = malloc(sizeof(char) * (a1s) + 4);

	if (a1s < a2s)
		return (a1);
	tmp = inf_div(a1, a2, bases);
	nb3 = inf_mult(a2, tmp, bases[0], bases[1]);
	res = inf_sub(a1, nb3, bases);
	return (res);
}
