/*
** EPITECH PROJECT, 2017
** my_sort_int_array
** File description:
** sort array int
*/

void my_swap(int *a,int *b);

void my_sort_int_array(int *array, int size)
{
	int	i = 0;
	while (i < size - 1) {
		if (array[i] > array[i + 1]) {
			my_swap(&array[i], &array[i + 1]);
			i = 0;
		} else
			i = i + 1;
	}
}
