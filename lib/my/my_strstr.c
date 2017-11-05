/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** strstr
*/

#include <unistd.h>

int	my_strlen(char *str);

int	check(int i, char const *str, char const *to_find)
{
	int	to_find_len = my_strlen(to_find);
	int	j = 0;
	int	k = i + j;
	while (to_find[j] == str[i + j] && str[k] != '\0') {
		to_find_len = to_find_len - 1;
		j = j + 1;
		k = i + j;
	}
	if (to_find_len == 0)
		return (1);
	return (0);
}

char	*my_strstr(char const *str, char const *to_find)
{
	int	i = 0;

	while (str[i] != '\0') {
		while (str[i] != to_find[0] && str[i] != '\0') {
			i = i + 1;
		}
		if (check(i, str, to_find) == 1)
			return (&str[i]);
		if (str[i] != '\0')
			i = i + 1;
	}
	return (NULL);
}
