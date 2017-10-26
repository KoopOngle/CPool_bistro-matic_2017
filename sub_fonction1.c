/*
** EPITECH PROJECT, 2017
** subfonction1.c
** File description:
** subfonctions
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
#include "mysub.h"

void add_minus(char *str)
{
	int i = 0;

	my_revstr(str);
	while (str[i] != '\0')
		i++;
	str[i] = '-';
	str[i + 1] = '\0';
	my_revstr(str);
}

void to_zero(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		str[i] = 0;
		i++;
	}
}

char *getResultMalloc(int size)
{
	char *result = malloc(sizeof(char) * size + 3);

	to_zero(result);
	return result;
}

char *getResultWithoutZero(char *str)
{
	int i = 0;

	while (str[i] == '0') {
		i++;
	}
	if (str[i] == '\0')
		return(&str[i - 1]);
	return (&str[i]);
}

int my_hundle_error(int argc, char **argv)
{
	int i = 1;

	if (argc != 3) {
		write(2, "invalid args\n", 13);
		return (0);
	}
	if (my_strlen(argv[1]) == 0 || my_strlen(argv[2]) == 0) {
		write(2, "invalid args\n", 13);
		return (0);
	}
	while (i < argc) {
		if (argv[i][0] == '-' && my_str_isnum(&argv[i][1]) == 0) {
			write(2, "invalid syntax\n", 15);
			return (0);
		}
		else if (my_str_isnum(argv[i]) == 0 && argv[i][0] != '-') {
			write(2, "invalid syntax\n", 15);
			return (0);
		}
		i++;
	}
	return (1);
}
