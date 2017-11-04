/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** str to word array
*/

#include <stdlib.h>

char *my_strdup(char const *str);
int my_strlen(char *str);
int my_show_word_array(char * const *tab);

int my_isalphanum(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
int get_len_word(char const *str)
{
	int i = 0;

	while (my_isalphanum(str[i]) == 1 && str[i] != '\0')
		i++;
	return (i);
}
int get_array_len(char const *str)
{
	int len = 1;
	int i = 0;

	while (str[i] != '\0') {
		if (my_isalphanum(str[i]) == 0
			&& my_isalphanum(str[i + 1]) == 1)
			len = len + 1;
		i = i + 1;
	}
	return (len);
}
char *replace_wrong_char(char *str)
{
	int len = my_strlen(str);
	int i = 0;
	char *strdup = my_strdup(str);

	while (i < len) {
		if (my_isalphanum(strdup[i]) == 0)
			strdup[i] = '\0';
		i = i + 1;
	}
	return (strdup);
}
char **my_str_to_word_array(char const *str)
{
	int strlen = my_strlen(str);
	char *strdup = my_strdup(str);
	char **array = malloc(sizeof(char *) * (get_array_len(str) + 1));
	int i = 0;
	int j = 0;

	array[get_array_len(str)] = 0;
	strdup = replace_wrong_char(str);
	while (i < strlen) {
		while(strdup[i] == '\0' && i < strlen)
			i = i + 1;
		if (strdup[i] != '\0')
			array[j] = my_strdup(&strdup[i]);
		j = j + 1;
		while(strdup[i] != '\0' && i < strlen)
			i = i + 1;
	}
	return (array);
}
