#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/inf_add.h"

char *modulo_a(char *a1, char *a2, char **bases)
{
        int i = 0;
        int a1s = my_strlen(a1);
	int a2s = my_strlen(a2);
        char *res = malloc(sizeof(char) * (a1s) + 4);
        char *nb3 = malloc(sizeof(char) * (a1s) + 4);
        char *tmp = malloc(sizeof(char) * (a1s) + 4);

	if (a1s < a2s)
		return (a1);
	
        tmp = inf_div(a1, a2, bases);
	printf("%s\n",tmp);
        nb3 = inf_mult(a2, tmp, bases[0], bases[1]);
	printf("%s\n",nb3);
        res = inf_sub(a1, nb3, bases);
	printf("%s\n",res);
	
        return (res);
}

int main(int ac, char **av)
{
	char **bases = malloc(sizeof(char *) * 2);
        bases[0] = my_strdup("0123456789");
        bases[1] = my_strdup("()+-");
	
        if (ac != 3)
                return (0);
        else
                printf("%s\n",modulo_a(av[1], av[2], bases));
	
}
