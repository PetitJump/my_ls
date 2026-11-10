int my_strncmp(char *s1, char *s2, int n)
{
    int i;

    for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    if (i >= n)
        return 0;
    if (s1[i] > s2[i])
        return 1;
    if (s1[i] < s2[i])
        return -1;
    return 0;
}
