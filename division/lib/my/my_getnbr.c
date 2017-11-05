/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** get nbr
*/
int	check_sign(char const *str, int i);
int	get_int_size(char const *str, int i);
int	change_str_int(char const *str, int size, int i);
int	my_ischaralpha(char c);

int	my_getnbr(char const *str)
{
	int	i = 0;
	int	iStart;
	int	sign;
	int	intSize;
	int	finalInt;

	while ((str[i] <= '0' || str[i] > '9')
		&& str[i] != '\0' && (my_ischaralpha(str[i]) == 0))
		i++;
	if (str[i] == '\0' || my_ischaralpha(str[i]) == 1)
		return (0);
	else {
		iStart = i;
		sign = check_sign(str, iStart);
		intSize = get_int_size(str, iStart);
		if (intSize > 10)
			return (0);
		finalInt = change_str_int(str, intSize, i) * sign;
		return (finalInt);
	}
}

int	my_ischaralpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	check_sign(char const *str, int i)
{
	int	sign = 1;
	while ((str[i - 1] == '-' || str[i - 1] == '+') && i > 0) {
		if (str[i - 1] == '-')
			sign = sign * (-1);
		i = i - 1;
	}
	return (sign);
}

int	get_int_size(char const *str, int i)
{
	int	size = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
		size = size + 1;
		i = i + 1;
	}
	return (size);
}

int	change_str_int(char const *str,int size, int i)
{
	int	intToReturn = 0;
	size = size + i;
	while (i < size) {
		if ((intToReturn * 10 + ((str[i] - '0')) > 2147483647))
			return (0);
		intToReturn = intToReturn * 10 + ((str[i] - '0'));
		i = i + 1;
	}
	return (intToReturn);
}
