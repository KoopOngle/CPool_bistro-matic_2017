#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

char *addinfcacl(char *str1, char *str2, char *base);
char *subinfcacl(char *str1, char *str2, char *base);
char *multcalc(char *a1, char *a2, char *base);

int in_to_base(char *base, char c)
{
	for(int i = 0; base[i] != '\0'; i++) {
		if (base[i] == c)
			return (i);
	}
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


int is_to_base(char *base, char c)
{
	for(int i = 0; base[i] != '\0'; i++) {
		if (base[i] == c)
			return (1);
	}
}

char *add_minus(char *str, char *opbase)
{
	char *res = malloc(sizeof(char) * (my_strlen(str)) + 2);
	res = my_revstr(str);
	res[my_strlen(str)] = opbase[3];
	res[my_strlen(str) + 1] = '\0';
	return (my_revstr(res));
}

char *clear_z(char *str, char *base, char *opbase)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(str)) + 1);
	int k = 0;
	int basel = my_strlen(base);
	int bool = 0;
	
	for (int i = 0; str[i] != '\0'; i++) {
		if ((in_to_base(base, str[i]) >= 0 && in_to_base(base, str[i]) <= basel) && bool != 1 && str[i] != opbase[3]) {
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
void k_clear_z(char **str, char *base)
{
	while (str[0][0] == base[0])
		str[0]++;
}

int verify(char *a1, char *a2, char *base, char *opbase)
{
	int i = 0;
	char *stra = clear_z(a1,base,opbase);
	char *strb = clear_z(a2,base,opbase);

	if (my_strlen(stra) < my_strlen(strb))
		return (0);
	else if (my_strlen(stra) > my_strlen(strb))
		return (1);
	while (stra[i] != '\0') {
		if (in_to_base(base,stra[i]) == in_to_base(base,strb[i]))
			i++;
		if (in_to_base(base,stra[i]) < in_to_base(base,strb[i]))
			return (0);
		i++;
	}
	return (1);
}

char *addinfcalc(char *a1, char *a2, char *base)
{
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	int tmp = 0;
	int i;
	int basel = my_strlen(base);
	char *res = malloc(sizeof(char) * (a1s + a2s) + 1);

	a1 = my_revstr(a1);
	a2 = my_revstr(a2);
	
	for(i = 0; i < a1s || i < a2s; i++) {
		if (i >= a1s)
			tmp += in_to_base(base, a2[i]);
		else if (i >= a2s)
			tmp += in_to_base(base, a1[i]);
		else
			tmp += in_to_base(base, a1[i]) + in_to_base(base, a2[i]);
		if (tmp >= basel)
			res[i] = base[tmp % basel];
		else
			res[i] = base[tmp];
		tmp = tmp / basel;
	}
	if (tmp == 1) {
		res[i] = base[1];
		res[i + 1] = '\0';
	} else
		res[i] = '\0';
	return (my_revstr(res));
}

char *subinfcalc(char *a1, char *a2, char *base, char *opbase)
{
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	int i;
	int basel = my_strlen(base);
	char *a1strdup = my_strdup(a1);
	char *a2strdup = my_strdup(a2);
	char *res = malloc(sizeof(char) * (a1s + a2s) + 1);

	my_revstr(a1strdup);
	my_revstr(a2strdup);
	
	for(i = 0; i < a1s || i < a2s; i++) {
		if (i >= a1s) {
			res[i] += in_to_base(base, a2strdup[i]);
		} else if (i >= a2s) {
			res[i] += in_to_base(base, a1strdup[i]);
		} else {
			res[i] += (in_to_base(base, a1strdup[i]) - in_to_base(base, a2strdup[i]));
		}
		if (res[i] < 0) {
			res[i] = base[res[i] + basel];
			res[i + 1] = -1;
		} else
			res[i] = base[res[i]];
		
	}
	if (res[i] == -1) {
		res[i] += base[0];
		res[i + 1] = '\0';
	} else
		res[i] = '\0';

	
	my_revstr(res);
	k_clear_z(&res, base);
	return (res);
}

char *divinfObscur(char *a1, char *a2, char *base, char *opbase)
{
	int k = 0;
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	char *sacrefice = subinfcalc(a1,a2,base, opbase);
	char *number = "1";
	char *a1strdup = my_strdup(a1);
	char *a3 = malloc(sizeof(char) * (a1s) + 2);
	char *res = malloc(sizeof(char) * (a1s) + 1);
	if (sacrefice[0] == base[0] - 1) {
		res[0] = base[1];
		return (res);
	}
	a3 = my_revstr(a1strdup);
	res[k] = 0;
	while (my_strlen(a3) >= a2s) {
		printf("%s - %s\n", a3, a2);
		a3 = subinfcalc(a3, a2, base, opbase);
		if (my_strlen(a3) < a2s || is_to_base(base,a3[0]) != 1)
			break;
		res = addinfcalc(number, res, base);
	}
	if (a2[1] == base[0])
		res = addinfcalc(number, res, base);
	return (res);
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


char *modulo(char *a1, char *a2, char *base, char *opbase)
{
	int i = 0;
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);

	//a1 = my_revstr(a1);
       	char *res = malloc(sizeof(char) * (a1s) + 1);
	char *nb3 = malloc(sizeof(char) * (a1s) + 1);
	char *tmp = malloc(sizeof(char) * (a1s) + 1);
	tmp = divinfObscur(a1, a2, base, opbase);
	printf("%s-%s-%s-%s-%s\n", tmp, nb3, res, a1, a2);
	nb3 = multcalc(a2, tmp, base);
	printf("%s-%s-%s-%s-%s\n", tmp, nb3, res, a1, a2);
	res = subinfcalc(a1,my_revstr(nb3),base, opbase);
	printf("%s-%s-%s-%s-%s\n", tmp, nb3, res, a1, a2);
	i = my_strlen(res) - 1;
	res[i] = '\0';
	return (my_revstr(res));
}

char *div_calc(char *a1, char *a2, char *base, char *opbase)
{
	int i = 0;
	int j = 0;
	int k = 0;

	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);

	char *a3 = malloc(sizeof(char) * (a1s) + 2);
	char *a4 = malloc(sizeof(char) * (a1s) + 2);
	char *res = malloc(sizeof(char) * (a1s) + 2);

	while (a1[i] != '\0') {
		a3[j] = a1[i];
		if (my_strlen(a3) >= a2s && verify(a3,a2,base,opbase) == 1) {
			a4 = divinfObscur(a3, a2, base, opbase);
			res[k] = a4[0];
			k++;
			printf("%s-%s\n", a4, a3);
			a3 = modulo(a3,a2,base, opbase);
			printf("%s-%s\n", a4, a3);
			j = my_strlen(a3) - 1;
		}
		j++;
		i++;
	}
	return (res);
}

char *inf_div(char *a1, char *a2, char *base, char *opbase)
{
	if ((a1[0] == opbase[3] && a2[0] == opbase[3]) && verify(a1,a2,base,opbase) == 1) {
		a1 = clear_z(a1,base,opbase);
		a2 = clear_z(a2,base,opbase);
	} else if (a1[0] == opbase[3] && verify(a1,a2,base,opbase) == 1) {
		a1 = clear_z(a1,base,opbase);
	} else if (a2[0] == opbase[3] && verify(a1,a2,base,opbase) == 1) {
		a2 = clear_z(a2,base,opbase);
	} else if ((a1[0] != opbase[3] && a2[0] != opbase[3]) && verify(a1,a2,base,opbase) == 1) {
		return(div_calc(a1,a2,base,opbase));
	} else
		return("0");
}

int main(int ac, char **av)
{
	char *base = "0123456789";
	char *opbase = "012-";
		if (ac != 3)
			return 0;
		else
			printf("%s\n",inf_div(av[1],av[2],base,opbase));
		return (0);
}
