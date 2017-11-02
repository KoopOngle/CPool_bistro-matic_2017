/*
** EPITECH PROJECT, 2017
** test par
** File description:
** test par
*/
#include "my.h"

char *get_strparentes(char **str, char* opbase)
{
        int i = 0;
	int par = 0;
        int parferm = 1;
        int ifirstpar;
        char *strdup = my_strdup(*str);

        while (strdup[i] != '\0' && parferm != 0) {
                if (strdup[i] == opbase[0] && par == 0) {
                        par += 1;
                        ifirstpar = i + 1;
                }
                if (strdup[i] == opbase[0] && par != 0)
			par += 1;
                if (strdup[i] == opbase[1]) {
                        par -=1;
                        parferm = (par == 1) ? 0 : 1;
                }
                i++;
        }
        *str = &str[0][i];
        if (parferm == 0) {
                strdup[i - 1] = '\0';
                return (&strdup[ifirstpar]);
	}
        return (*str);
}

int	main(int argc, char **argv)
{
	char *str = my_strdup(argv[1]);
        char **bases = malloc(sizeof(char *) * 2);
        bases[0] = my_strdup(argv[2]);
        bases[1] = my_strdup(argv[3]);
        while (str[0] != '\0') {
                my_putstr(get_strparentes(&str, bases[1]));
                my_putstr("\n");
        }
	return (0);
}
