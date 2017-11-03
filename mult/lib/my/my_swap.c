/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swap 2 variables donnée
*/

void	my_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
