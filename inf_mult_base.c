/*
** EPITECH PROJECT, 2017
** Mult_inf
** File description:
** fonctionnel
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "inf_add.h"

void k_clear_z_mult(char **str, char *base, char *opbase)
{
	if (str[0][0] == opbase[3])
		str[0]++;
	while (str[0][0] == base[0] && str[0][1] != '\0')
		str[0]++;
}

int add_zero(int j, char *res, char *base)
{
	int l = 0;

	while (l < j) {
		res[l] = base[0];
		l++;
	}
	return (l);
}

char *multcalc(char *a1, char *a2, char *base)
{
	char **res = malloc(sizeof(char *) * my_strlen(a2) + 2);
	int i = my_strlen(a1);
	int j = my_strlen(a2);
	int zero_count = 0;
	int k = 0;
	int l = 0;

	while (j > 0) {
		res[zero_count] = malloc(sizeof(char) * (my_strlen(a1) + my_strlen(a2) + 2));
		l = add_zero(zero_count,res[zero_count],base);
		while (i > 0) {
			k += (in_to_base(base, a1[i - 1])) * (in_to_base(base, a2[j - 1]));
			if (k >= my_strlen(base)) {
				res[zero_count][l] = base[k % my_strlen(base)];
			} else if (k <= my_strlen(base))
				res[zero_count][l] = base[k];
			k = k/my_strlen(base);
			i = i - 1;
			l = l + 1;
		}
		if (k != 0)
			res[zero_count][l] = base[k];
		my_revstr(res[zero_count]);
		k = 0;
		i = my_strlen(a1);
		zero_count += 1;
		j = j - 1;
	}
	res[zero_count] = 0;
	i = 1;
	while (res[i] != 0) {
		res[0] = addinfcalc(res[0],res[i],base);
		i = i + 1;
	}
	return(res[0]);
}

char *inf_mult(char *a1, char *a2, char *base, char *opbase)
{	
	char *tmp = (my_strlen(a1) < my_strlen(a2)) ? a1 : a2;
	char *result;

	if (my_strlen(a1) < my_strlen(a2)) {
		a1 = (my_strlen(a1) < my_strlen(a2)) ?  a2 : tmp;
		a2 = (my_strlen(a2) > my_strlen(tmp)) ? tmp : a2;
	}
	if (a1[0] == opbase[3] && a2[0] == opbase[3]) {
		k_clear_z_mult(&a1, base, opbase);
		k_clear_z_mult(&a2, base, opbase);
		return (multcalc(a1,a2,base));
	}
	else if (a1[0] == opbase[3] || a2[0] == opbase[3]) {
		k_clear_z_mult(&a1, base, opbase);
		k_clear_z_mult(&a2, base, opbase);
		result = multcalc(a1, a2, base);
		return ((result[0] == base[0]) ? result : add_minus(result, opbase));
	} else {
		k_clear_z_mult(&a1, base, opbase);
		k_clear_z_mult(&a2, base, opbase);
		return (multcalc(a1,a2,base));
	}
}
