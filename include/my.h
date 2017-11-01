/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
int mynew_compute_square_root(int nb);
int check_nbr(int nb);
int get_tot_len_two(char **tab);
int mymy_strlen(char const *str);
int check(int i, char const *str, char const *to_find);
int get_array_len(char const *str);
int get_len_word(char const *str);
int my_isalphanum(char c);
char *replace_wrong_char(char *str);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_getnbrstr(char **str);
void my_sort_int_array(int *a, int n);
int my_compute_power_rec(int n, int p);
int my_compute_square_root(int n);
int my_is_prime(int n);
int my_find_prime_sup(int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src,int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *str, char const *src);
int my_strncmp(char const *str, char const *src,int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int n);
char *my_strcat(char *s1, char const *s2);
char *my_strncat(char *s1, char const *s2, int n);
char *my_strdup(char const *src);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
#endif
