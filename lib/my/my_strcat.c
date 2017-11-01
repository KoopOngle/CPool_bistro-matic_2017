/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** str cat
*/

char	*my_strcat(char *dest, char const *src)
{
	int	i = 0;
	int	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0') {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char my_str_charcat(char *dest, char c);
{
	int     i = 0;

        while (dest[i] != '\0')
		i++;
	dest[i] = c;
        dest[i + 1] = '\0';
	return (dest);
}
