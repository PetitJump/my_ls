static int end(int result, int nb_neg)
{
    if (nb_neg % 2 == 1)
        return -result;
    return result;
}

static int is_in_int(int result, int nb_neg)
{
    if (result < 0 && nb_neg % 2 == 0)
        return 0;
    return 1;
}

int my_getnbr(char const *str)
{
    int result = 0;
    int nb_neg = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if ((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '+')
            break;
        if (str[i] == '-')
            nb_neg++;
        if (str[i] >= '0' && str[i] <= '9'){
            result = result * 10 + (str[i] - '0');
        }
    }
    if (!is_in_int(result, nb_neg))
        return 0;
    return end(result, nb_neg);
}
