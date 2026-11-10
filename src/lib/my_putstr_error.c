#include <unistd.h>

int my_putstr_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], sizeof(char));
    return 0;
}
