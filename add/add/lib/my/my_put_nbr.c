/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my put number
*/

int	my_putchar(char c);
void	check_nbr(int nb);

int	my_put_nbr(int nb)
{
	if (nb >= 0 && nb < 10) {
		my_putchar('0' + nb);
		return (0);
	} else {
		check_nbr(nb);
	}
	return (0);
}

void	check_nbr(int nb)
{
	if (nb < 0) {
		if(nb == -2147483648) {
			my_put_nbr(-214748364);
			my_put_nbr(8);
			return;
		}
		my_putchar('-');
		my_put_nbr(-nb);
	} else {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	}
}
