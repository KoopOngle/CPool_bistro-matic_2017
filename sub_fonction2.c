/*
** EPITECH PROJECT, 2017
** subfonction2.c
** File description:
** subfonction2
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include "mysub.h"

int my_new_strcmp(char *str, char *str2)
{
	char *compstr;
	int strlen1 = my_strlen(str);
	int strlen2 = my_strlen(str2);
	int strlendif;
	int i = 0;

	if (strlen1 > strlen2) {
		strlendif = strlen1 - strlen2;
		compstr = malloc(sizeof(char) * strlen1);
		for (i = 0; i < strlendif; ++i) {
			compstr[i] = '0';
		}
		compstr[i] = '\0';
		my_concat_str(compstr, str2);
		return (my_strcmp(str, compstr));
	} else if (strlen1 < strlen2) {
		strlendif = strlen2 - strlen1;
		compstr = malloc(sizeof(char) * strlen2);
		for (i = 0; i < strlendif; i++) {
			compstr[i] = '0';
		}
		compstr[i] = '\0';
		my_concat_str(compstr, str);
		return (my_strcmp(compstr, str2));
	} else
		return(my_strcmp(str,str2));
}

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

char *chooseGoodOp(char sign1, char sign2, char *str1dup, char *str2dup, char* base)
{
	char *result;

	if (sign1 == '-' && sign2 == '-') {
		result = my_add_inf(str1dup, str2dup, base);
		if (result[0] != '0')
			add_minus(result);
	} else if (sign1 == '-' || sign2 == '-') {
		if (my_new_strcmp(str1dup, str2dup) > 0)
			result = my_sub_inf(str1dup, str2dup);
		else
			result = my_sub_inf(str2dup, str1dup);
		if ((my_new_strcmp(str1dup, str2dup) > 0 && sign1 == '-') ||
			(my_new_strcmp(str2dup, str1dup) > 0 && sign2 == '-'))
			add_minus(result);
	} else
		result = my_add_inf(str1dup, str2dup, base);
	return (result);
}

