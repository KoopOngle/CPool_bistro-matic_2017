/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** get nbr
*/

#include "my.h"
#include "inf_add.h"

void add_minusgetnbr(char *str, char *opbase)
{
        int i = 0;

        my_revstr(str);
	while (str[i] != '\0')
                i++;
        str[i] = opbase[3];
        str[i + 1] = '\0';
        my_revstr(str);
	}


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

static int	check_signa(char *str, int i, char *opbase)
{
	int	sign = 1;
	while ((str[i - 1] == opbase[3] || str[i - 1] == opbase[2]) && i > 0) {
		if (str[i - 1] == opbase[3])
			sign = sign * (-1);
		i = i - 1;
	}
	return (sign);
}
static int	get_int_sizea(char *str, int i, char *base)
{
	int	size = 0;
	int	baselen = my_strlen(base);
	
	while (is_in_base(str[i], base) == 1 && str[i] != '\0') {
		size = size + 1;
		i = i + 1;
	}
	return (size);
}

char	*my_getnbrstrbase(char **str, char **bases)
{
	int	i = 0;
	char	*result;
	int	sign;
	int	intSize;

	while (is_in_base(str[0][i], bases[0]) == 0
		&& str[0][i] != '\0')
		i++;
	if (str[0][i] == '\0')
		return (bases[0]);
	else {
		result = my_strdup(&str[0][i]);
		sign = check_signa(*str, i, bases[1]);
		intSize = get_int_sizea(result, 0, bases[0]);
		result[intSize] = '\0';
		*str = &str[0][i + intSize];
		if (sign == -1)
			add_minusgetnbr(result, bases[1]);
		return (result);
	}
}


/*int	main(int argc, char **argv)
{
	char *str = my_strdup(argv[1]);
	char **bases = malloc(sizeof(char *) * 2);
	bases[0] = my_strdup(argv[2]);
	bases[1] = my_strdup(argv[3]);
	while (str[0] != '\0') {
		my_putstr(my_getnbrstrbase(&str, bases));
		my_putstr("\n");
	}
	return (0);
	}*/

