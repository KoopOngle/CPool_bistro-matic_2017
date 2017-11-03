/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** find the next sup prime
*/

int	my_is_prime(int nb);

int	my_find_prime_sup(int nb)
{
	while (my_is_prime(nb) == 0 && (nb <= 2147483647))
		nb = nb + 1;
	return (nb);
}
