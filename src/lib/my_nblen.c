int nb_len(int nb)
{
    int len = 1;

    if (nb < 0)
        len++;
    for (; nb / 10 != 0; nb /= 10)
        len++;
    return len;
}
