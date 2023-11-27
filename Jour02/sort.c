#include <stdio.h>

int my_strlen(char *str)
{
    int i = -1;

    while (str[++i] != '\0');
    return (i);
}

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

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

char **sort(char **strs) {
    int i = 0;

    while(strs[i] != NULL && strs[i + 1] != NULL) {
        if (my_strcmp(strs[i], strs[i + 1]) > 0) {
            char *tmp = strs[i];
            strs[i] = strs[i + 1];
            strs[i + 1] = tmp;
            i = 0;
        } else {
            i++;
        }
    }
    return (strs);
}