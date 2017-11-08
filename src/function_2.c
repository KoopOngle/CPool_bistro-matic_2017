/*
** EPITECH PROJECT, 2017
** function2.c
** File description:
** function2
*/

#include <stdlib.h>
#include "inf_add.h"
#include "my.h"

void my_concat_str(char *src, char *str)
{
	int i = 0;
	int j = 0;

	while (src[i] != '\0')
		i++;
	while (str[j] != '\0') {
		src[i] = str[j];
		i++;
		j++;
	}
	src[i] = '\0';
}

int my_comp_nbrstr(char *str, char *str2, char *base)
{
	int i = 0;
	int calcul = 0;

	while (str[i] != '\0' && str2[i] != '\0') {
		calcul += in_to_base(base, str[i]) - in_to_base(base, str2[i]);
		if (str[i] == str2[i])
			i++;
		else
			break;
	}
	return (calcul);
}

char *chooseGoodOp(char sign1, char sign2, char **strs, char **bases)
{
	char *result;

	if (sign1 == bases[1][3] && sign2 == bases[1][3]) {
		result = addinfcalc(strs[0], strs[1], bases[0]);
		if (result[0] != bases[0][0])
			result = add_minus(result, bases[1]);
	} else if (sign1 == bases[1][3] || sign2 == bases[1][3]) {
		if (my_new_strcmp(strs[0], strs[1], bases) > 0)
			result = subinfcalc(strs[0], strs[1], bases[0]);
		else
			result = subinfcalc(strs[1], strs[0], bases[0]);
		if ((my_new_strcmp(strs[0], strs[1], bases) > 0 && sign1 == bases[1][3]) ||
		    (my_new_strcmp(strs[1], strs[0], bases) > 0 && sign2 == bases[1][3]))
			result = add_minus(result, bases[1]);
	} else
		result = addinfcalc(strs[0], strs[1], bases[0]);
	return (result);
}

int my_new_strcmp(char *str, char *str2, char **bases)
{
	char *compstr;
	int strlendif;
	int i = 0;
	char *strdup = k_clear_zb(str, bases[0], bases[1]);
	char *str2dup = k_clear_zb(str2, bases[0], bases[1]);
	int strlen1 = my_strlen(strdup);
	int strlen2 = my_strlen(str2dup);

	if (strlen1 > strlen2) {
		strlendif = strlen1 - strlen2;
		compstr = malloc(sizeof(char) * strlen1);
		for (i = 0; i < strlendif; ++i)
			compstr[i] = bases[0][0];
		compstr[i] = '\0';
		my_concat_str(compstr, str2dup);
		return (my_comp_nbrstr(strdup, compstr, bases[0]));
	} else if (strlen1 < strlen2) {
		strlendif = strlen2 - strlen1;
		compstr = malloc(sizeof(char) * strlen2);
		for (i = 0; i < strlendif; i++) {
			compstr[i] = bases[0][0];
		}
		compstr[i] = '\0';
		my_concat_str(compstr, strdup);
		return (my_comp_nbrstr(compstr, str2dup, bases[0]));
	} else 
		return(my_comp_nbrstr(strdup, str2dup, bases[0]));
}
