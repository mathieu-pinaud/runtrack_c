#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0')
        i += 1;
    return (i);
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

char **split(char *src, char c) {
    int i = 0;
    int spaces = 2;
    int j = 0;
    int tmp = 0;
    
    src = trim(src);
    while (src[i] != '\0') {
        if (src[i] == c)
            spaces += 1;
        i++;
    }
    i = 0;
    char **result = malloc(sizeof(char *) * (spaces + 1));
    spaces = 0;
    while (src[i] != '\0') {
        if (src[i] == c || src[i + 1] == '\0') {
            result[spaces] = malloc(sizeof(char) * (i - tmp + 2));
            while (tmp <= i) {
                if (src[i] != c || tmp != i) {
                    result[spaces][j] = src[tmp];
                    j += 1;
                }
                tmp+= 1;
            }
            result[spaces][j] = '\0';
            spaces += 1;
            j = 0;
        }
        i+= 1;
    }
    free(src);
    result[spaces] = NULL;
    return (result);
}

void my_free_array(char **array) {
    int i = 0;
    while (array[i] != NULL) {
        free(array[i]);
        i += 1;
    }
    free(array);
}