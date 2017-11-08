#include "include/my.h"
#include "include/inf_add.h"
#include <stdlib.h>

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

char *k_clear_zb(char *str, char *base, char *opbase)
{
	char *tmp = my_strdup(str);

	if (tmp[0] == opbase[3])
		tmp++;
	while (tmp[0] == base[0] && tmp[1] != '\0')
		tmp++;
	return (tmp);
}

void k_clear_z(char **str, char *base)
{
	while (str[0][0] == base[0] && str[0][1] != '\0')
		str[0]++;
}
