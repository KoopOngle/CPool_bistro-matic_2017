#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int in_to_base(char *base, char c)
{	
	for(int i = 0; base[i] != '\0'; i++) {
		if (c == base[i])
			return (i);
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

char *subinfcalc(char *a1, char *a2, char *base)
{
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	int i;
	int basel = my_strlen(base);
	char *res = malloc(sizeof(char) * (a1s + a2s) + 1);

	a1 = my_revstr(a1);
	a2 = my_revstr(a2);
	
	for(i = 0; i < a1s || i < a2s; i++) {
		if (i >= a1s) {
			res[i] += in_to_base(base, a2[i]);
		} else if (i >= a2s) {
			res[i] += in_to_base(base, a1[i]);
		} else {
			res[i] += (in_to_base(base, a1[i]) - in_to_base(base, a2[i]));
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
	return (my_revstr(res));
}

// A REMPLACER POUR PLUS DE PROPRETER ! // RAPPEL TOI 3 LIGNE ET C'EST BON OUBLI PAS
char *miniclear(char *str)
{
	int k = 0;
	char *tmp = malloc(sizeof(char) * (my_strlen(str)) + 1);

	for (int i = 0; str[i] != '\0'; i++) {
		if (i > 0) {
			tmp[k] = str[i];
			k++;
		}
	}
	tmp[k] = '\0';
	return (tmp);
}

char *a_sign(char *a1, char *a2, char *base, char *opbase)
{
	char *tmp;
	char *res;

	if (a1[0] == opbase[3] && a2[0] == opbase[3]) {
		a1 = clear_z(a1, base);
		a2 = clear_z(a2, base);
		//printf("DEBUG 1 : %s %s\n", a1, a2);
		res = addinfcalc(a1, a2, base);
		res = add_minus(res,opbase);
	} else if (a1[0] == opbase[3]) {
		//printf("DEBUG 2 : %s %s\n", a1, a2);
		a1 = clear_z(a1, base);
		a2 = clear_z(a2, base);
		//printf("DEBUG 2 : %s %s\n", a1, a2);
		res = clear_z(subinfcalc(a1, a2, base), base);
		if (res[0] != '\0')
			res = add_minus(res,opbase);
		else
			*res = base[0];
	}else if (a2[0] == opbase[3]) {
		a1 = clear_z(a1, base);
		a2 = clear_z(a2, base);
		//printf("DEBUG 3 : %s %s\n", a1, a2);
		res = clear_z(subinfcalc(a1, a2, base), base);
	}
	if (res[0] == base[1] && res[1] == opbase[3]) {
		res = miniclear(res);
	}
	return (res);
}

char *b_sign(char *a1, char *a2, char *base, char *opbase)
{
	int bool = 0;
	char *tmp;
	char *res;

	if (a2[0] == opbase[3]) {
		a1 = clear_z(a1, base);
		a2 = clear_z(a2, base);
		if (my_strlen(a1) < my_strlen(a2)) {
			tmp = a1;
			a1 = a2;
			a2 = tmp;
			bool = 1;
		}
		res = clear_z(subinfcalc(a1, a2, base), base);
	}
	
	if (bool == 1)
		res = add_minus(res, opbase);
	return (res);
}

char *inf_add(char *a1, char *a2, char *base, char *opbase)
{
	char *tmp = (my_strlen(a1) < my_strlen(a2)) ? a1 : a2;
	
	if (a2[1] < a1[0] && a2[0] == opbase[3] && my_strlen(a2) > my_strlen(a1))
	if (a1[0] == opbase[3] || a2[0] == opbase[3]) {
		if (my_strlen(a1) < my_strlen(a2)) {
			a1 = (my_strlen(a1) < my_strlen(a2)) ?  a2 : tmp;
			a2 = (my_strlen(a2) > my_strlen(tmp)) ? tmp : a2;
		}	
		return(a_sign(a1,a2,base,opbase));
	}else if (a2[0] == opbase[3] && a2[1] < a1[0]) {
		return(a_sign(a1,a2,base,opbase));
	}else	
		return (addinfcalc(a1,a2,base));
}

int main(int ac, char **av)
{
	char *base = "0123456789";
	char *opbase = "012-";
	printf("%s\n",inf_add(av[1],av[2],base,opbase));
	return (0);
}
