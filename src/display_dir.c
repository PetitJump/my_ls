#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int print_error(char *dir)
{
    my_putstr_error("ls: impossible d'accéder à '");
    my_putstr_error(dir);
    my_putstr_error("' : Aucun fichier ou répertoire de ce type\n");
    return 84;
}

static int display_list(char **liste)
{
    for (int i = 0; liste[i] != NULL; i++){
        my_putstr(liste[i]);
    }
    return 0;
}

static int end_function(char **tri, DIR *directory, int born)
{
    tri[born] = NULL;
    display_list(tri);
    my_putchar('\n');
    closedir(directory);
    return 0;
}

int display_solo(char *dir)
{
    DIR *directory = opendir(dir);
    struct dirent *file;
    int born = 0;
    char *tri[1000];

    if (directory == NULL)
        return print_error(dir);
    while (1){
        file = readdir(directory);
        if (file == NULL)
            break;
        if (file->d_name[0] != '.' && file->d_name[0] != ' '){
            tri[born] = file->d_name;
            born++;
            tri[born] = "  ";
            born++;
        }
    }
    end_function(tri, directory, born);
    return 0;
}

int display_total_list(char ***total_list, falgs_t *f)
{
    for (int i = 0; total_list[i] != NULL; i++){
        display_list(total_list[i]);
        if (total_list[i + 1] != NULL && !f->d)
            my_putchar('\n');
    }
    return 0;
}
