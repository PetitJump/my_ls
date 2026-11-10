#include "../include/my.h"

int main(int argc, char **argv)
{
    falgs_t f = {0};

    flags_to_zero(&f);
    if (argc == 1){
        display_solo(".");
        return 0;
    }
    return print_ls(&f, argc, argv, get_flags(&f, argv, argc));
}
