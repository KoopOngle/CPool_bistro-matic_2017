/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** my_strncpy
*/

int	mymy_strlen(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		i++;
	}
	return (i);
}

char	*my_strncpy(char *dest, char const *src, int n)
{
	int	i = 0;
	if (n <= mymy_strlen(src)) {
		while (i < n) {
			dest[i] = src[i];
			i++;
		}
	} else {
		while (src[i] != '\0') {
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
