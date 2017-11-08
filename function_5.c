#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/inf_add.h"

char *modulo(char *a1, char *a2, char **bases)
{
	int i = 0;
	int a1s = my_strlen(a1);
	char *res = malloc(sizeof(char) * (a1s) + 1);
        char *nb3 = malloc(sizeof(char) * (a1s) + 1);
	char *tmp = malloc(sizeof(char) * (a1s) + 1);
                                                                                                    
        tmp = div_calc_next(a1, a2, bases);
	//printf("3 = %s|%s|%s|%s|%s\n\n", res,nb3,tmp,a1,a2);
        nb3 = inf_mult(a2, tmp, bases[0], bases[1]);
	//printf("4 = %s|%s|%s|%s|%s\n\n", res,nb3,tmp,a1,a2);
        res = inf_sub(a1,nb3, bases);
	//printf("5 = %s|%s|%s|%s|%s\n\n", res,nb3,tmp,a1,a2);
        i = my_strlen(res) + 1;                                                                     
        res[i] = '\0';

	
	return (res);
}

int is_full_of_zero(char *str, char *base)
{
	int i = 0;
	int k = 1;

	while (str[i] != '\0') {
		if (str[i] != base[0])
			k = 0;
		i++;
	}
	return (k);
}

char is_divisble(char *a1, char *a2, char **bases) {
	char *str = inf_div(a1, a2, bases);
	//printf("-------%s\n", str);
	if (a1[0] == bases[0][0])
		return (bases[0][0]);
	else
		return (str[0]);
}

char *zero_res(char **bases)
{
	char *res = malloc(sizeof(bases[0][0]) + 1);
	res[0] = bases[0][0];
	res[1] = '\0';

	return (res);
}
