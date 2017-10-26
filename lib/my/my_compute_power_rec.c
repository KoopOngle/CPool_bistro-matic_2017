/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** recusive power
*/

int	my_compute_power_rec(int nb, int p)
{
	int	exnb = nb;
	if (p == 0)
		nb = 1;
	else if (p < 0)
		nb = 0;
	else {
		nb = nb * my_compute_power_rec(nb, p - 1);
	}
	if (nb == -2147483648 && exnb > 0)
		return (0);
	return (nb);
}
