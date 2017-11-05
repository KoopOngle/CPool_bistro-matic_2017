/*
** EPITECH PROJECT, 2017
** my show word array
** File description:
** my show word array
*/

#include <stdlib.h>

int my_strlen(char const *str);
void my_putstr(char const *str);

int get_tot_len_two(char **tab)
{
	int len = 0;
	int i = 0;

	while (tab[i] != '\0') {
		len += my_strlen(tab[i]) + 1;
		i++;
	}
	return (len);
}

int my_show_word_array(char * const *tab)
{
	int i = 0;
	int y = 0;
	int k = 0;
	char *result;

	result = malloc(sizeof(char) * (get_tot_len_two(tab) + 1));
	while (tab[i] != '\0') {
		while (tab[i][y] != '\0') {
			result[k] = tab[i][y];
			y++;
			k++;
		}
		i++;
		y = 0;
		result[k] = '\n';
		k++;
	}
	result[k] = '\0';
	my_putstr(result);
	return (0);
}
