/*
** EPITECH PROJECT, 2017
** inf_add.h
** File description:
** inf add h
*/

#ifndef INF_ADD_H_
#define INF_ADD_H_
int in_to_base(char *base, char c);
char *add_minus(char *str, char *opbase);
void k_clear_z(char **str, char *base);
char *addinfcalc(char *a1, char *a2, char *base);
char *subinfcalc(char *a1, char *a2, char *base);
void my_concat_str(char *src, char *str);
int my_new_strcmp(char *str, char *str2, char **bases);
char *chooseGoodOp(char sign1, char sign2, char **strs, char **bases);
char *inf_add(char *str1, char *str2, char **bases);
char *inf_sub(char *str1, char *str2, char **bases);
char *clear_z(char *str, char *base);
int add_zero(int j, char *res, char *base);
char *multcalc(char *a1, char *a2, char *base);
char *inf_mult(char *a1, char *a2, char *base, char *opbase);
#endif
