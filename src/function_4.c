/*
** EPITECH PROJECT, 2017
** function4.c
** File description:
** function4
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "inf_add.h"

char *clear_za(char *str, char *base, char *opbase)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(str)) + 1);
	int k = 0;
	int basel = my_strlen(base);
	int bool = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if ((in_to_base_a(base, str[i]) > 0 && in_to_base_a(base, str[i]) <= basel) && bool != 1 && str[i] != opbase[3]) {
			tmp[k] = str[i];
			k++;
			bool = 1;
		}
		else if (bool == 1) {
			tmp[k] = str[i];
			k++;
		}
	}
	tmp[k] = '\0';
	return (tmp);
}

int verify(char *a1, char *a2, char **bases)
{
	int i = 0;
	char *stra = clear_za(a1,bases[0],bases[1]);
	char *strb = clear_za(a2,bases[0],bases[1]);

	if (my_strlen(stra) < my_strlen(strb))
		return (0);
	else if (my_strlen(stra) > my_strlen(strb))
		return (1);
	while (stra[i] != '\0') {
		if (in_to_base_a(bases[0],stra[i]) == in_to_base_a(bases[0],strb[i]))
			i++;
		if (in_to_base_a(bases[0],stra[i]) < in_to_base_a(bases[0],strb[i]))
			return (0);
		i++;
	}
	return (1);
}

int verify_m(char *a1, char *a2, char **bases)
{
	int i = 0;
	char *stra = k_clear_za(a1,bases[0],bases[1]);
	char *strb = k_clear_za(a2,bases[0],bases[1]);

	if (my_strlen(stra) < my_strlen(strb))
		return (0);
	else if (my_strlen(stra) > my_strlen(strb))
		return (1);
	while (stra[i] != '\0') {
		if (in_to_base_a(bases[0],stra[i]) < in_to_base_a(bases[0],strb[i]) &&
		    in_to_base_a(bases[0],stra[i - 1]) <= in_to_base_a(bases[0],strb[i - 1]) &&
		    in_to_base_a(bases[0],stra[0]) <= in_to_base_a(bases[0],strb[0]))
			return (0);
		i++;
	}
	return (1);
}

char *div_calc_next(char *a1, char *a2, char **bases)
{
	int i = 0;
	char *number = "1";
	char *t_number = "0";
	char *stra = my_strdup(a1);
	char *strb = my_strdup(a2);

	while (stra[0] != bases[1][3]) {
		stra = inf_sub(stra, strb, bases);
		t_number = inf_add(number, t_number, bases);
	}
	if (stra[0] == bases[1][3]) {
		t_number = inf_sub(t_number, number, bases);
	}
	return (t_number);
}
