int my_strlen(char const *str)
{
    int total = 0;

    for (int i = 0; str[i] != '\0'; i++)
        total += 1;
    return total;
}
