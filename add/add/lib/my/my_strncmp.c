/*
** EPITECH PROJECT, 2017
** strncmp
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;
	int	calcul = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') || i < n) {
		calcul += s1[i] - s2[i];
		if (s1[i] == s2[i])
			i++;
		else
			break;
	}
	return (calcul);
}
