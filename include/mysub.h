/*
** EPITECH PROJECT, 2017
** mysub.h
** File description:
** mysub.h
*/

#ifndef MYSUB_H_
#define MYSUB_H_
int my_new_strcmp(char *str, char *str2);
void my_concat_str(char *src, char *str);
char *chooseGoodOp(char sign1, char sign2, char *str1dup, char *str2dup, char *base);
void add_minus(char *str, char *opbase);
void to_zero(char *str);
char *getResultMalloc(int size);
char *getResultWithoutZero(char *str);
int my_hundle_error(int argc, char **argv);
char *my_sub_inf(char *str1, char *str2);
char *infinadd(char *str1, char *str2, char *base);
char *my_add_inf(char *str1, char *str, char *base);
#endif
