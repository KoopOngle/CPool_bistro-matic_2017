#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char *infinadd(char *str1, char *str2, char *base);

void j_putchar(char c)
{
	write(1, &c, 1);
}

int j_strlen(char *str)
{
	int count = 0;
	
	for (int i = 0;str[i] != '\0'; i = i +1) {
		count = count + 1;
	}
	return (count);
}

void	base_to_str(char *base, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      str[i] = base[str[i] - 1];
      i = i + 1;
    }
}

void j_putnbr(int nb)
{
	if (nb <= -2147483647 || nb >= 2147483647) {
		write(2, "ERROR\n", 7);
	} else if (nb > 9) {
		j_putnbr(nb / 10);
		j_putnbr(nb % 10);
	} else
		j_putchar(nb + 48);
}

int int_to_char(int i)
{
	return(i + 48);
}


char *j_evilstr(char *str)
{
	int i = 0;
	int size = j_strlen(str);
	char c;

	while (i < size / 2) {
		c = *(str + i);
		*(str + i) = *(str + size - i - 1);
		*(str + size - i - 1) = c;
		++i;
	}
	return (str);
}

int char_to_int(int i)
{
	return(i - 48);
}

int get_pos_base(char c, char *base)
{
	int i = 0;

	while (base[i] != c)
		i = i + 1;
	return (i);
}

int add_zero(int j, char *res, char *base)
{
	int l = 0;
	
	while (l < j) {
		res[l] = base[0];
		l = l + 1;
	}
	return (l);
}


char *j_strdup(char *str)
{
	int i = 0;
	char *res = malloc(sizeof(char) * (j_strlen(str) + 1));

	while (i < j_strlen(str)) {
		res[i] = str[i];
		i = i + 1;
	}
	res[i] = '\0';
	return (res);
}

void j_swapstr(char **a1, char **a2)
{
	int i = 0;
	int j = 0;
	char *str1 = malloc(j_strlen(*a2));
	char *str2 = malloc(j_strlen(*a1));
	

	str1 = my_strcpy(str1,*a1);
	str2 = my_strcpy(str2,*a2);
	
	*a1 = str2;
	*a2 = str1;
	//printf("%s\n", *a1);
	//printf("%s\n", *a2);
}

void bail_sombre(char **a1, char **a2)
{
	int i = 0;
	int j = 0;
	char *str1 = malloc(sizeof(char) * j_strlen(*a1) + 1);
	char *str2 = malloc(sizeof(char) * j_strlen(*a2) + 1);


	while (a1[0][i] != '\0') {
		if (a1[0][i] >= '0' && a1[0][i] <= '9') {
			str1[j] = a1[0][i];
			j++;
		}
		i++;
	}
	str1[j] = '\0';
	i = 0;
	j = 0;
	
	while (a2[0][i] != '\0') {
		if (a2[0][i] >= '0' && a2[0][i] <= '9') {
			str2[j] = a2[0][i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	
	*a1 = str1;
	*a2 = str2;
}

void ges_neg(char **a1, char **a2)
{
	int i = 0;
	int j = 0;
	int count = 0;
	if (a1[0][0] == '-' && a2[0][0] == '-') {
		printf("~~%s,%s~~", a1[0], a2[0]);
		bail_sombre (&a1[0],&a2[0]);
		//return;
	}
		
	while (a1[0][i] != '\0' && a2[0][j] != '\0') {
		if (a1[0][i] == '-') {
			j_swapstr(&a1[i],&a2[i]);
			//printf("{%s\n", a1[i]);
			//printf("{%s\n", a2[i]);
		}
		if (a2[0][j] == '-')
			count++;
		//printf("%d\n", count);
		i = i + 1;
		j = j + 1;
	}
	if (count % 2 == 1)
		j_putchar('-');
}

char *multinf(char *a1, char *a2, char *base)
{
	char **res = malloc(sizeof(char *) * j_strlen(a2) + 2);
	int i = j_strlen(a1);
	int j = j_strlen(a2);
	int zero_count = 0;
	int k = 0;
	int l = 0;
	
	while (j > 0) {
		res[zero_count] = malloc(sizeof(char) * (j_strlen(a1) + j_strlen(a2) + 2));
		l = add_zero(zero_count,res[zero_count],base);
		while (i > 0) {
			k += (get_pos_base(a1[i - 1], base)) * (get_pos_base(a2[j - 1], base));
			//printf("[%d]\n", k);
			if (k >= j_strlen(base) && !(a1[i - 1] == '-' || a2[j - 1] == '-')) {
				//printf("  '%d'  \n", k);
				res[zero_count][l] = base[k % j_strlen(base)];
			} else if (k <= j_strlen(base))
				res[zero_count][l] = base[k];
			k = k/j_strlen(base);
			i = i - 1;
			l = l + 1;
		}
		if (k != 0)
			res[zero_count][l] = base[k];
		j_evilstr(res[zero_count]);
		//printf("  |%s|  \n", res[zero_count]);
		i = j_strlen(a1);
		zero_count += 1;
		j = j - 1;
	}
	res[zero_count] = 0;
	i = 1;
	while (res[i] != 0) {
		//printf("%s \n", res[0]);
		res[0] = infinadd(res[0],res[i],base);
		i = i + 1;
	}
	return(res[0]);
}

int main(int ac, char **av)
{
	char base[] = "0123456789";
	int o = 0;
	char *res;
	char *str = av[1];
	char *str1 = av[2];
	
	ges_neg(&str,&str1);
	
	//printf("%s\n", str);
	//printf("%s\n", str1);
	multinf(str,str1,base);
	my_putchar('\n');
	return 0;
}
