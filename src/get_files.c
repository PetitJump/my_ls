#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "../include/my.h"

static int no_flags(falgs_t *f)
{
    if (f->a || f->big_r || f->d || f->l || f->t)
        return 0;
    return 1;
}

static int take_files(DIR *directory, char **tri, int *born, falgs_t *f)
{
    struct dirent *file = NULL;

    while (1){
        file = readdir(directory);
        if (file == NULL)
            break;
        if ((file->d_name[0] != '.' && file->d_name[0] != ' ') || f->a){
            tri[*born] = file->d_name;
            *born += 1;
            tri[*born] = "  ";
            *born += 1;
        }
    }
    return 0;
}

char *build_path(char *dir, char *name)
{
    char *path = malloc(my_strlen(dir) + my_strlen(name) + 2);

    my_strncpy(path, dir, my_strlen(dir));
    path[my_strlen(dir)] = '/';
    my_strncpy(path + my_strlen(dir) + 1, name, my_strlen(name));
    path[my_strlen(dir) + my_strlen(name) + 1] = '\0';
    return path;
}

char **sub_dir(char *dir, char **tri, int start, int end)
{
    char **list_dir = malloc(100 * sizeof(char *));
    int count_dir = 0;
    struct stat stbuff;
    char *path;

    for (int i = start; i < end; i++){
        path = build_path(dir, tri[i]);
        if (stat(path, &stbuff) == 0 && S_ISDIR(stbuff.st_mode)
            && tri[i][0] != '.'){
            list_dir[count_dir] = path;
            count_dir++;
        }
    }
    list_dir[count_dir] = NULL;
    return list_dir;
}

static int take_files_r(char *dir, char **tri, int *born, falgs_t *f)
{
    char **list_dir;
    int tmp = *born;

    take_files(opendir(dir), tri, born, f);
    list_dir = sub_dir(dir, tri, tmp, *born);
    for (int i = 0; list_dir[i] != NULL; i++){
        tri[*born] = "\n\n";
        tri[*born + 1] = list_dir[i];
        tri[*born + 2] = ":\n";
        *born += 3;
        take_files_r(list_dir[i], tri, born, f);
    }
    free(list_dir);
    return 0;
}

static char **get_files_no_flag(falgs_t *f, char *dir,
    char **tri, int is_multiple)
{
    DIR *directory = opendir(dir);
    int born = 0;

    if (directory == NULL)
        return NULL;
    if (is_multiple || f->big_r){
        tri[0] = dir;
        tri[1] = ":\n";
        born += 2;
    }
    if (f->big_r){
        take_files_r(dir, tri, &born, f);
    } else
        take_files(directory, tri, &born, f);
    tri[born] = "\n";
    tri[born + 1] = NULL;
    return tri;
}

char **get_files(falgs_t *f, char *dir, int is_multiple)
{
    char **tri = malloc(10000 * sizeof(char));
    struct stat stbuff;

    if (stat(dir, &stbuff) == -1){
        my_putstr_error("ls: impossible d'accéder à '");
        my_putstr_error(dir);
        my_putstr_error("' : Aucun fichier ou répertoire de ce type\n");
        return NULL;
    }
    if (!S_ISDIR(stbuff.st_mode) || f->d){
        tri[0] = dir;
        tri[1] = "\n\0";
        return tri;
    }
    if (no_flags(f) || f->a || f->big_r){
        return get_files_no_flag(f, dir, tri, is_multiple);
    }
    return NULL;
}
