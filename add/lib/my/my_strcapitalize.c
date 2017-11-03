/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** capitalise a string
*/

char	*my_strlowcase(char *str);

char	*my_strcapitalize(char *str)
{
	int	i = 0;
	int	k;

	str = my_strlowcase(str);
	while (str[i] != '\0') {
		k = i - 1;
		if(i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		else if ((str[i] >= 'a' && str[i] <= 'z')
			 && !(str[k] >= 'a' && str[k] <= 'z')
			 && !(str[k] >= '0' && str[k] <= '9')
			 && !(str[k] >= 'A' && str[k] <= 'Z'))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
