/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** str dup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
	char *dest;
	int i = 0;
	int size = my_strlen(src);

	dest = malloc(sizeof(char) * (size + 1));
	while (i < size) {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
