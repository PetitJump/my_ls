#ifndef MY_H
    #define MY_H

typedef struct {
    int d;
    int t;
    int a;
    int l;
    int big_r;
} falgs_t;

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_putchar(char c);
int print_error(char *dir);
int my_putstr_error(char const *str);
int my_put_nbr(int nb);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char *src, int n);
int nb_len(int nb);
int my_getnbr(char const *str);
int display_total_list(char ***total_list, falgs_t *f);
int flags_to_zero(falgs_t *f);
int get_flags(falgs_t *f, char **argv, int argc);
char **get_files(falgs_t *f, char *dir, int is_multiple);
int print_ls(falgs_t *f, int argc, char **argv, int is_mutiple);
char *my_take_nbr(int nb);
int display_solo(char *dir);

#endif
