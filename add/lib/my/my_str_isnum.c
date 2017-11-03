/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** is alpha
*/

int my_str_isnum(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
