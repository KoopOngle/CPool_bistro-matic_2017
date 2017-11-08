/*
** EPITECH PROJECT, 2017
** inf_add.h
** File description:
** inf add h
*/

#ifndef INF_ADD_H_
#define INF_ADD_H_
int in_to_base(char *base, char c);
int in_to_base_a(char *base, char c);
int is_to_base(char *base, char c);
int is_in_to_base(char *base, char c);
char *add_minus(char *str, char *opbase);
char *add_minus_a(char *str, char *opbase);
void k_clear_z(char **str, char *base);
char *k_clear_za(char *str, char *base, char *opbase);
char *k_clear_zb(char *str, char *base, char *opbase);
char *clear_za(char *str, char *base, char *opbase);
char *addinfcalc(char *a1, char *a2, char *base);
char *subinfcalc(char *a1, char *a2, char *base);
void my_concat_str(char *src, char *str);
int my_new_strcmp(char *str, char *str2, char **bases);
char *chooseGoodOp(char sign1, char sign2, char **strs, char **bases);
//int my_comp_nbrstr(char *str, char *str2, char *base)
char *inf_add(char *str1, char *str2, char **bases);
char *inf_sub(char *str1, char *str2, char **bases);
char *clear_z(char *str, char *base);
int add_zero(int j, char *res, char *base);
char *multcalc(char *a1, char *a2, char *base);
char *inf_mult(char *a1, char *a2, char *base, char *opbase);
void k_clear_z_mult(char **str, char *base, char *opase);
char *inf_div(char *a1, char *a2, char **base);
char *divinf(char *a1, char *a2, char **bases);
char *div_calc_next(char *a1, char *a2, char **bases);
int verify(char *a1, char *a2, char **bases);
int verify_m(char *a1, char *a2, char **bases);
char *modulo(char *a1, char *a2, char **bases);
int is_full_of_zero(char *str, char *base);
char is_divisble(char *a1, char *a2, char **bases);
char *inf_mod(char *a1, char *a2, char **base);
char *a_sign(char *a1, char *a2, char **base);
#endif
