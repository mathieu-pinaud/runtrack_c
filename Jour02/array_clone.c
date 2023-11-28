#include <stdio.h>
#include <stdlib.h>

int my_strlen (char*str){
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char **array_clone(char **src, int n) {
    char **res;
    int i = 0;
    int j = 0;

    while (src[i] != NULL)
        i++;
    if (n < i)
        i = n;
    res = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (src[i] != NULL && i < n) {
        res[i] = malloc(sizeof(char) * (my_strlen(src[i]) + 1));
        while (src[i][j] != '\0') {
            res[i][j] = src[i][j];
            j+= 1;
        }
        res[i][j] = '\0';
        j = 0;
        i+= 1;
    }
    res[i] = NULL;
    return (res);
}