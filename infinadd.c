/*
** EPITECH PROJECT, 2017
** infinadd.c
** File description:
** addition de nombre infini
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include "mysub.h"

char *my_sub_inf(char *str1, char *str2)
{
	char *str1dup = my_strdup(str1);
	char *str2dup = my_strdup(str2);
	char *result;
	int str1len = my_strlen(str1);
	int str2len = my_strlen(str2);
	int i = 0;

	if (str1len > str2len)
		result = getResultMalloc(str1len);
	else
		result = getResultMalloc(str2len);
	my_revstr(str1dup);
	my_revstr(str2dup);
	for (i = 0; i < str1len || i < str2len ; i++) {
		if (i >= str1len)
			result[i] += str2dup[i];
		else if (i >= str2len)
			result[i] += str1dup[i];
		else
			result[i] += str1dup[i] - str2dup[i] + 48;
		if (result [i] < '0') {
			result[i] = result[i] + '9' - '0' + 1;
			result[i + 1] = -1;
		}
	}
	if (result[i] == -1) {
		result[i] += '0';
		result[i + 1] = '\0';
	}
	else
		result[i] = '\0';
	return (getResultWithoutZero(my_revstr(result)));
}

char *my_add_inf(char *str1, char *str2)
{
	char *str1dup = my_strdup(str1);
	char *str2dup = my_strdup(str2);
	char *result;
	int str1len = my_strlen(str1);
	int str2len = my_strlen(str2);
	int i = 0;

	if (str1len > str2len)
		result = getResultMalloc(str1len);
	else
		result = getResultMalloc(str2len);
	my_revstr(str1dup);
	my_revstr(str2dup);
	for (i = 0; i < str1len || i < str2len ; i++) {
		if (i >= str1len)
			result[i] += str2dup[i];
		else if (i >= str2len)
			result[i] += str1dup[i];
		else
			result[i] += str1dup[i] + str2dup[i] - 48;
		if (result[i] > '9') {
			result[i] = result[i] - '9' + '0' - 1;
			result[i + 1] = 1;
		}
	}
	if (result[i] == 1) {
		result[i] += '0';
		result[i + 1] = '\0';
	}
	else
		result[i] = '\0';
	return (getResultWithoutZero(my_revstr(result)));
}

char *infinadd(char *str1, char *str2)
{
	char sign1 = '+';
	char sign2 = '+';
	char *str1dup = my_strdup(str1);
	char *str2dup = my_strdup(str2);
	char *result;

	if (str1[0] == '-') {
		sign1 = '-';
		str1dup = &str1dup[1];
	}
	if (str2[0] == '-') {
		sign2 = '-';
		str2dup = &str2dup[1];
	}
	result = chooseGoodOp(sign1, sign2, str1dup, str2dup);
	
	return (result);
}


int	main(int argc, char **argv)
{
	if (my_hundle_error(argc, argv) == 0)
		return (84);
	my_putstr(infinadd(argv[1], argv[2]));
	my_putstr("\n");
	return (0);
}
