#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/inf_add.h"

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

char *k_clear_za(char *str, char *base, char *opbase)
{
	char *tmp = my_strdup(str);
	
	if (tmp[0] == opbase[3])
		tmp++;
	while (tmp[0] == base[0] && tmp[1] != '\0')
		tmp++;
	return (tmp);
}

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

char *modulo(char *a1, char *a2, char **bases)
{
	int i = 0;
	int a1s = my_strlen(a1);
	char *res = malloc(sizeof(char) * (a1s) + 1);
        char *nb3 = malloc(sizeof(char) * (a1s) + 1);
	char *tmp = malloc(sizeof(char) * (a1s) + 1);
                                                                                                    
        tmp = div_calc_next(a1, a2, bases);
        nb3 = inf_mult(a2, tmp, bases[0], bases[1]);
        res = inf_sub(a1,nb3, bases);
        i = my_strlen(res) + 1;                                                                     
        res[i] = '\0';

	
	return (res);
}

int is_full_of_zero(char *str, char *base)
{
	int i = 0;
	int k = 1;

	while (str[i] != '\0') {
		if (str[i] != base[0])
			k = 0;
		i++;
	}
	return (k);
}

char is_divisble(char *a1, char *a2, char **bases) {
	char *str = inf_div(a1, a2, bases);

	if (a1[0] == bases[0][0])
		return (bases[0][0]);
	else
		return (str[0]);
}

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
		if (my_strlen(a3) >= a2s && my_new_strcmp(a2,a3,bases) <= 0) {
			a4 = div_calc_next(a3,a2,bases);
			res[k] = a4[0];
			k++;
			if (a4[1] != 0) {
			res[k] = a4[1];
			k++;
			}
			if (stra[i + 1] != '\0')
				a3 = modulo(a3,a2,bases);
			j = my_strlen(a3) - 1;
			bool = 1;
		} else if ((stra[i] == bases[0][0] || is_in_to_base(bases[0],a3[j]) == 1) && my_new_strcmp(a2,a3,bases) > 0 && bool == 1) {
			res[k] = is_divisble(a3,a2,bases);
			k++;
		}
		j++;
		i++;
	}
	res[k] = '\0';
	return (res);
}

char *a_sign(char *a1, char *a2, char **bases)
{
	char *stra = my_strdup(a1);
	char *strb = my_strdup(a2);

	if ((a1[0] == bases[1][3] && a2[0] == bases[1][3]) && my_new_strcmp(a1, a2, bases) >= 0) {
		return(divinf(stra, strb, bases));
		
	} else if (a1[0] == bases[1][3] && my_new_strcmp(a1, a2, bases) >= 0) {
		return(add_minus(divinf(stra, strb, bases),bases[1]));
		
	} else if (a2[0] == bases[1][3] && my_new_strcmp(a1, a2, bases) >= 0)
	        return(add_minus(divinf(stra, strb, bases),bases[1]));
}

char *inf_div(char *a1, char *a2, char **bases)
{
	char *stra = my_strdup(a1);
	char *strb = my_strdup(a2);
	char *strzero = malloc(sizeof(char) * 2);
	strzero[0] = bases[0][0];

	stra = clear_za(a1, bases[0], bases[1]);
	strb = clear_za(a2, bases[0], bases[1]);
	if ((a1[0] == bases[1][3] && a2[0] == bases[1][3])
	    && my_new_strcmp(a1, a2, bases) >= 0) {
		return(a_sign(stra, strb, bases));
	} else if ((a1[0] != bases[1][3] && a2[0] != bases[1][3])
		   && (my_new_strcmp(a1, a2, bases) >= 0)) {
	        return(divinf(stra, strb, bases));
	} else
		return(strzero);
}
