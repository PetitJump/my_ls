#include <unistd.h>

int my_put_nbr(int nb)
{
    int less;
    int nb_to_print;

    if (nb < 0){
        less = '-';
        write(1, &less, sizeof(char));
        if (nb <= -10)
            my_put_nbr(-(nb / 10));
        nb_to_print = -(nb % 10) + '0';
        write(1, &nb_to_print, sizeof(char));
    } else {
        if (nb >= 10)
            my_put_nbr(nb / 10);
        nb_to_print = nb % 10 + '0';
        write(1, &nb_to_print, sizeof(char));
    }
    return 0;
}
