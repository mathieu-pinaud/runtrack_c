int my_strcmp(char *s1, char *s2)
{
    int i = -1;

    while (s1[++i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
        i +=1;
    }
    return (0);
}