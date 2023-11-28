#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char *str)
{
    int i = -1;

    while (str[++i] != '\0');
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
        i +=1;
    }
    return (0);
}

char *trim(char *src)
{
    int start = 0;
    int end = my_strlen(src) - 1;
    int k = 0;
    char *trimmed;
    while (src[start] != '\0' && src[start] == ' ')
        start += 1;
    while (end >= 0 && src[end] == ' ')
        end -= 1;
    if (start > end)
        return (NULL);
    trimmed = malloc(sizeof(char) * (end - start + 2));
    while (start <= end)
    {
        trimmed[k] = src[start];
        start += 1;
        k += 1;
    }
    trimmed[k] = '\0';
    return (trimmed);
}

char **sort(char **strs) {
    int i = 1;
    while (strs[i] != NULL) {
        strs[i] = trim(strs[i]);
        i++;
    }
    i = 1;
    while(strs[i] != NULL && strs[i + 1] != NULL) {
        if (my_strcmp(strs[i], strs[i + 1]) > 0) {
            char *tmp = strs[i];
            strs[i] = strs[i + 1];
            strs[i + 1] = tmp;
            i = 1;
        } else {
            i++;
        }
    }
    return (strs);
}

void my_putstr(char *str)
{
    int i = -1;
    while (str[++i] != '\0')
        write(1, &str[i], 1);
}

int main(int ac, char **av)
{
    ac += 1;
    char **sorted = sort(av);
    int i = 1;
    while (sorted[i] != NULL) {
        my_putstr(sorted[i]);
        sorted[i + 1] == NULL ? write(1, "\n", 1) : write(1, " ", 1);
        i++;
    }
}