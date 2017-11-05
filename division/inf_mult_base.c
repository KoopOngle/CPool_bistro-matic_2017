#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "inf_add.h"

char *clear_z(char *str, char *base)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(str)) + 1);
	int k = 0;
	int basel = my_strlen(base);
	int bool = 0;
	
	for (int i = 0; str[i] != '\0'; i++) {
		if ((in_to_base(base, str[i]) > 0 && in_to_base(base, str[i]) <= basel) && bool != 1) {
			tmp[k] = str[i];
			k++;
			bool = 1;
		}
		else if (bool == 1) {
			tmp[k] = str[i];
			k++;
		}
	}
	tmp[k] = '\0';
	
	return (tmp);
}

int add_zero(int j, char *res, char *base)
{
	int l = 0;

	while (l < j) {
		res[l] = base[0];
		l++;
	}
	return (l);
}

char *multcalc(char *a1, char *a2, char *base)
{
	char **res = malloc(sizeof(char *) * my_strlen(a2) + 2);
	int i = my_strlen(a1);
	int j = my_strlen(a2);
	int zero_count = 0;
	int k = 0;
	int l = 0;
	
	while (j > 0) {
		res[zero_count] = malloc(sizeof(char) * (my_strlen(a1) + my_strlen(a2) + 2));
		l = add_zero(zero_count,res[zero_count],base);
		while (i > 0) {
			k += (in_to_base(base, a1[i - 1])) * (in_to_base(base, a2[j - 1]));
			//printf("[%d]\n", k);
			if (k >= my_strlen(base)) {
				//printf("  '%d'  \n", k);
				res[zero_count][l] = base[k % my_strlen(base)];
			} else if (k <= my_strlen(base))
				res[zero_count][l] = base[k];
			k = k/my_strlen(base);
			i = i - 1;
			l = l + 1;
		}
		if (k != 0)
			res[zero_count][l] = base[k];
		my_revstr(res[zero_count]);
		//printf("  |%s|  |%d|\n", res[zero_count] , k);
		k = 0;
		i = my_strlen(a1);
		zero_count += 1;
		j = j - 1;
	}
	res[zero_count] = 0;
	i = 1;
	while (res[i] != 0) {
		//printf("%s %d\n", res[0], i);
		res[0] = addinfcalc(res[0],res[i],base);
		i = i + 1;
	}
	return(res[0]);
}

char *inf_mult(char *a1, char *a2, char *base, char *opbase)
{
	char *tmp = (my_strlen(a1) < my_strlen(a2)) ? a1 : a2;
	
	if (my_strlen(a1) < my_strlen(a2)) {
		a1 = (my_strlen(a1) < my_strlen(a2)) ?  a2 : tmp;
		a2 = (my_strlen(a2) > my_strlen(tmp)) ? tmp : a2;
	}
	if (a1[0] == opbase[3] && a2[0] == opbase[3]) {
		a1 = clear_z(a1,base);
		a2 = clear_z(a2,base);
		return (multcalc(a1,a2,base));
	}
	else if (a1[0] == opbase[3] || a2[0] == opbase[3]) {
		a1 = clear_z(a1,base);
		a2 = clear_z(a2,base);
		return (add_minus(multcalc(a1,a2,base),opbase));
	} else {		
		a1 = clear_z(a1,base);
		a2 = clear_z(a2,base);
		return (multcalc(a1,a2,base));
	}
}

/*int main(int ac , char **av)
{
	char *base = "0123456789";
	char *opbase  = "012-";

	if (ac != 3)
		return (0);
	else
		printf("%s\n",multinf(av[1],av[2],base,opbase));
	return (0);
}
*/