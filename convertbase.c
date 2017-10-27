/*
** EPITECH PROJECT, 2017
** convertbase.c
** File description:
** convertbase
*/

#include "my.h"
#include <stdlib.h>

int getPosInBase(char c, char *base) {
	int i = 0;
	while (base[i] != c) {
		i++;
	}
	return (i);
}

char *my_convertbase(char *str, char*base_beg, char*base_end)
{
	char *result = malloc(sizeof(char) * (my_strlen(str) * my_strlen(base_beg)));
	int base_begsize = my_strlen(base_beg);
	int base_endsize = my_strlen(base_end);
	int i = my_strlen(str);
	int j = 0;
	int k = 0;

	while (i > 0 || j != 0) {
		if (i > 0)
			j+= getPosInBase(str[i], base_beg);
		result[k] = base_end[j % base_endsize];
		j = j / base_endsize;
		k++;
		i--;
	}
	result[k] = '\0';
	my_revstr(result);
	return (result);	
}

int	main(int argc, char **argv)
{
	my_putstr(my_convertbase(argv[1], argv[2], argv[3]));
	return (0);
}
