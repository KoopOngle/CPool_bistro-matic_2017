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
	int i = 0;
	char *strdup = my_strdup(str);
	char *res = malloc(sizeof(char) * (my_strlen(str)) + 4);
	
	res = my_revstr(strdup);
	while (res[i] != '\0')
		i++;
	res[i] = opbase[3];
	res[i + 1] = '\0';
	return (my_revstr(res));
}

void k_clear_z(char **str, char *base)
{
	while (str[0][0] == base[0] && str[0][1] != '\0')
		str[0]++;
}

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

// A REMPLACER POUR PLUS DE PROPRETER ! // RAPPEL TOI 3 LIGNE ET C'EST BON OUBLI PAS
/*char *miniclear(char *str)
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
*/

/*char *inf_add(char *a1, char *a2, char *base, char *opbase)
  {
  char *tmp = (my_strlen(a1) < my_strlen(a2)) ? a1 : a2;
  
  if (a1[0] == opbase[3] || a2[0] == opbase[3]) {
  if (my_strlen(a1) < my_strlen(a2)) {
  a1 = (my_strlen(a1) < my_strlen(a2)) ?  a2 : tmp;
  a2 = (my_strlen(a2) > my_strlen(tmp)) ? tmp : a2;
  }	
  return(a_sign(a1,a2,base,opbase));
  }else	
  return (addinfcalc(a1,a2,base));
  }*/

void my_concat_str(char *src, char *str)
{
        int i = 0;
        int j = 0;
        while (src[i] != '\0')
                i++;
        while (str[j] != '\0') {
                src[i] = str[j];
                i++;
                j++;
        }
        src[i] = '\0';
}

int my_comp_nbrstr(char *str, char *str2, char *base)
{
        int     i = 0;
        int     calcul = 0;
        while (str[i] != '\0' && str2[i] != '\0') {
                calcul += in_to_base(base, str[i]) - in_to_base(base, str2[i]);
                if (str[i] == str2[i])
                        i++;
                else
                        break;
        }
        return (calcul);
}

int my_new_strcmp(char *str, char *str2, char **bases)
{
        char *compstr;
        int strlen1 = my_strlen(str);
        int strlen2 = my_strlen(str2);
        int strlendif;
        int i = 0;

        if (strlen1 > strlen2) {
                strlendif = strlen1 - strlen2;
                compstr = malloc(sizeof(char) * strlen1);
                for (i = 0; i < strlendif; ++i) {
                        compstr[i] = bases[0][0];
                }
                compstr[i] = '\0';
                my_concat_str(compstr, str2);
                return (my_comp_nbrstr(str, compstr, bases[0]));
        } else if (strlen1 < strlen2) {
                strlendif = strlen2 - strlen1;
                compstr = malloc(sizeof(char) * strlen2);
                for (i = 0; i < strlendif; i++) {
                        compstr[i] = bases[0][0];
                }
                compstr[i] = '\0';
                my_concat_str(compstr, str);
                return (my_comp_nbrstr(compstr, str2, bases[0]));
        } else 
                return(my_comp_nbrstr(str, str2, bases[0]));
}


char *chooseGoodOp(char sign1, char sign2, char **strs, char **bases)
{
        char *result;

        if (sign1 == bases[1][3] && sign2 == bases[1][3]) {
                result = addinfcalc(strs[0], strs[1], bases[0]);
                if (result[0] != bases[0][0])
                        result = add_minus(result, bases[1]);
	} else if (sign1 == bases[1][3] || sign2 == bases[1][3]) {
                if (my_new_strcmp(strs[0], strs[1], bases) > 0)
                        result = subinfcalc(strs[0], strs[1], bases[0]);
                else
                        result = subinfcalc(strs[1], strs[0], bases[0]);
                if ((my_new_strcmp(strs[0], strs[1], bases) > 0 && sign1 == bases[1][3]) ||
		    (my_new_strcmp(strs[1], strs[0], bases) > 0 && sign2 == bases[1][3]))
                        result = add_minus(result, bases[1]);
        } else
                result = addinfcalc(strs[0], strs[1], bases[0]);
        return (result);
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



/*int main(int ac, char **av)
{
	char **bases = malloc(sizeof(char *) * 2);
	char *base = "0123456789";
	char *opbase = "012-";
	bases[0] = base;
	bases[1] = opbase;
	printf("%s\n",inf_sub(av[1],av[2],bases));
	return (0);
}
*/
