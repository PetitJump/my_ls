#include <stdlib.h>
#include "../include/my.h"

int flags_to_zero(falgs_t *f)
{
    f->a = 0;
    f->big_r = 0;
    f->d = 0;
    f->l = 0;
    f->t = 0;
    return 0;
}

static void test_all_f(char **argv, int i, int j, falgs_t *f)
{
    if (argv[i][j] == 'a')
        f->a = 1;
    if (argv[i][j] == 'R')
        f->big_r = 1;
    if (argv[i][j] == 'd')
        f->d = 1;
    if (argv[i][j] == 'l')
        f->l = 1;
    if (argv[i][j] == 't')
        f->t = 1;
}

int get_flags(falgs_t *f, char **argv, int argc)
{
    int total_file = 0;

    for (int i = 1; i < argc; i++){
        for (int j = 0; j < my_strlen(argv[i]) && argv[i][0] == '-'; j++){
            test_all_f(argv, i, j, f);
        }
        if (argv[i][0] != '-')
            total_file++;
    }
    return total_file;
}

static int do_solo(char ***total_files, falgs_t *f)
{
    total_files[0] = get_files(f, ".", 0);
    total_files[1] = NULL;
    display_total_list(total_files, f);
    return 0;
}

static int end_printls(char ***total_files, int argc,
    int result, falgs_t *f)
{
    total_files[argc] = NULL;
    display_total_list(total_files, f);
    free(total_files);
    return result;
}

int print_ls(falgs_t *f, int argc, char **argv, int is_mutiple)
{
    char ***total_files = malloc(10000 * sizeof(char));
    int result = 0;
    int born = 0;
    char **tmp;

    if (is_mutiple == 0)
        return do_solo(total_files, f);
    for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-')
            continue;
        tmp = get_files(f, argv[i], is_mutiple > 1);
        if (tmp == NULL){
            result = 84;
        } else {
            total_files[born] = tmp;
            born += 1;
        }
    }
    return end_printls(total_files, argc, result, f);
}
