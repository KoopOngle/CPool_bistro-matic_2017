#include <stdio.h>
#include <stdlib.h>
#include "include/inf_add.h"
#include "include/my.h"


char *addinfcalc(char *a1, char *a2, char *base)
{
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	int tmp = 0;
	int i;
	int basel = my_strlen(base);
	char *res = malloc(sizeof(char) * (a1s + a2s) + 1);
	char *a1strdup = my_revstr(my_strdup(a1));
	char *a2strdup = my_revstr(my_strdup(a2));
	
	for(i = 0; i < a1s || i < a2s; i++) {
		if (i >= a1s)
			tmp += in_to_base(base, a2strdup[i]);
		else if (i >= a2s)
			tmp += in_to_base(base, a1strdup[i]);
		else
			tmp += in_to_base(base, a1strdup[i]) + in_to_base(base, a2strdup[i]);
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
	my_revstr(res);
	k_clear_z(&res, base);
	free(a1strdup);
	free(a2strdup);
	return (res);
}

char *subinfcalc(char *a1, char *a2, char *base)
{
	int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
	int i;
	int basel = my_strlen(base);
	char *res = malloc(sizeof(char) * (a1s + a2s) + 1);
        char *a1strdup = my_revstr(my_strdup(a1));
	char *a2strdup = my_revstr(my_strdup(a2));
	
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
	free(a1strdup);
	free(a2strdup);
	my_revstr(res);
	k_clear_z(&res, base);
	return (res);
}

char *inf_add(char *str1, char *str2, char **bases)
{
        char sign1 = '+';
        char sign2 = '+';
	char **strs = malloc(sizeof(char *) * 2);
        char *result;
	strs[0] = my_strdup(str1);
	strs[1] = my_strdup(str2);

        if (str1[0] == bases[1][3]) {
		sign1 = bases[1][3];
                strs[0] = &strs[0][1];
        }
        if (str2[0] == bases[1][3]) {
                sign2 = bases[1][3];
                strs[1] = &strs[1][1];
        }
        result = chooseGoodOp(sign1, sign2, strs, bases);

        return (result);
}

char *inf_sub(char *str1, char *str2, char **bases)
{
	char *str1dup = my_strdup(str1);
	char *str2dup = my_strdup(str2);
	if (str2dup[0] == bases[1][3]) {
		str2dup++;
	}
	else {
		str2dup = add_minus(str2dup, bases[1]);
	}
	return (inf_add(str1dup, str2dup, bases));
}
