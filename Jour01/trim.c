#include <stdio.h>
#include <stdlib.h>

int my_strlen (char*str);

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