/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** is prime
*/

int     mynew_compute_square_root(int nb)
{
	int     i = 0;

	while ((i * i) < nb)
		i++;
	return (i);
}

int	my_is_prime(int nb)
{
	int	i = mynew_compute_square_root(nb);
	int	y = 2;

	if (nb == 1 || nb <= 0)
		return (0);
	while(y < i) {
		if ((nb % y) == 0)
			return (0);
		y++;
	}
	return (1);
}
