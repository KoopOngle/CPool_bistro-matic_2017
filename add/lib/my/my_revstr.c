/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** my_revstr
*/

int	my_strlen(char const *str);

char	*my_revstr(char *str)
{
	int	i = 0;
	int	n = my_strlen(str) - 1;
	char	temp;

	while (i < n) {
		temp = str[i];
		str[i] = str[n];
		str[n] = temp;
		n--;
		i++;
	}
	return(str);
}
