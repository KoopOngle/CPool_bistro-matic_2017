/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** my compute square root
*/

int	my_compute_square_root(int nb)
{
	int	i = 0;

	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return (i);
	else
		return(0);
}
