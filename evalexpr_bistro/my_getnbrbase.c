/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** get nbr
*/

#include "my.h"


int	is_in_base(char c, char *base)
{
	int result = 0;
	int i = 0;

	while (base[i] != '\0') {
		if (base[i] == c)
			result = 1;
		i++;
	}
	return (result);
}

static int	check_sign(char *str, int i, char *base)
{
	int	sign = 1;
	while ((str[i - 1] == base[3] || str[i - 1] == base[2]) && i > 0) {
		if (str[i - 1] == base[3])
			sign = sign * (-1);
		i = i - 1;
	}
	return (sign);
}

static int	get_int_size(char *str, int i, char *base)
{
	int	size = 0;
	int	baselen = my_strlen(base);
	
	while (is_in_base(str[i], base) == 1 && str[i] != '\0') {
		size = size + 1;
		i = i + 1;
	}
	return (size);
}

char	*my_getnbrstrbase(char **str, char *base)
{
	int	i = 0;
	char	*result;
	int	sign;
	int	intSize;

	while (is_in_base(str[0][i], base) == 0
		&& str[0][i] != '\0')
		i++;
	if (str[0][i] == '\0')
		return (base);
	else {
		result = my_strdup(&str[0][i]);
		sign = check_sign(*str, i, base);
		intSize = get_int_size(*str, i, base);
		result[intSize] = '\0';
		*str = &str[0][i + intSize];
		return (result);
	}
}


int	main(int argc, char **argv)
{
	char *str = my_strdup(argv[1]);

	my_putstr(my_getnbrstrbase(&str, argv[2]));
	return (0);
}
