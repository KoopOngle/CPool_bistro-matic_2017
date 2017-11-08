/*
** EPITECH PROJECT, 2017
** divinf.c
** File description:
** division infini
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "inf_add.h"

char *inf_div(char *a1, char *a2, char **bases);

char *divinf(char *a1, char *a2, char **bases)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int bool = 0;
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	char *stra = my_strdup(a1);
	char *strb = my_strdup(a2);
	char *a3 = malloc(sizeof(char) * (a1s + a2s) + 2);
	char *a4;
	char *res = malloc(sizeof(char) * (a1s + a2s) + 2);

	a3[j] = 0;
	res[k] = 0;
	while (stra[i] != '\0') {
		a3[j] = stra[i];
		if (my_strlen(a3) >= a2s && my_new_strcmp(a2, a3, bases) <= 0) {
			a4 = div_calc_next(a3, a2, bases);
			res[k] = a4[0];
			k++;
			if (a4[1] != 0) {
				res[k] = a4[1];
				k++;
			}
			if (stra[i + 1] != '\0')
				a3 = modulo(a3, a2, bases);
			j = my_strlen(a3) - 1;
			bool = 1;
		} else if ((stra[i] == bases[0][0] || is_in_to_base(bases[0], a3[j]) == 1) && my_new_strcmp(a2, a3, bases) > 0 && bool == 1) {
			res[k] = is_divisble(a3, a2, bases);
			k++;
		}
		j++;
		i++;
	}
	res[k] = '\0';
	return (res);
}

int div_zero(char *a1, char *a2, char **bases)
{
	int size_base = my_strlen(a1) + my_strlen(a2);
	int count_neg = 0;
	int count_zero = 0;

	for (int i  = 0; a1[i] != '\0'; i++) {
		if (a1[i] == bases[0][0])
			count_zero += 1;
		if (a1[i] == bases[1][3])
			count_neg += 1;
	}
	for (int i  = 0; a2[i] != '\0'; i++) {
		if (a2[i] == bases[0][0])
			count_zero += 1;
		if (a2[i] == bases[1][3])
			count_neg += 1;
	}
	if ((count_neg + count_zero) == size_base)
		return (1);
	else if (a2[0] == bases[0][0])
		return (1);
	else
		return (0);
}

char *inf_div(char *a1, char *a2, char **bases)
{
	char *stra = my_strdup(a1);
	char *strb = my_strdup(a2);
	char *strzero = malloc(sizeof(char) * 2);

	strzero[0] = bases[0][0];
	if (div_zero(a1, a2, bases) == 1) {
		my_putstr("syntax error");
		exit(84);
	}
	stra = clear_za(a1, bases[0], bases[1]);
	strb = clear_za(a2, bases[0], bases[1]);
	if ((a1[0] == bases[1][3] && a2[0] == bases[1][3]) && verify_m(a1, a2, bases) == 1)
		return(divinf(stra, strb, bases));
	else if (a1[0] == bases[1][3] && verify_m(a1, a2, bases) == 1)
		return(add_minus_a(divinf(stra, strb, bases), bases[1]));
	else if (a2[0] == bases[1][3] && verify_m(a1, a2, bases) == 1)
		return(add_minus_a(divinf(stra, strb, bases), bases[1]));
	else if ((a1[0] != bases[1][3] && a2[0] != bases[1][3]) && verify_m(a1, a2, bases) == 1)
		return(divinf(stra, strb, bases));
	else
		return(strzero);
}
