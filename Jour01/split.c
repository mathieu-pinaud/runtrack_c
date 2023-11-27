#include <stdio.h>
#include <stdlib.h>

char *trim(char *src);

char **split(char *src) {
    int i = 0;
    int spaces = 2;
    int j = 0;
    int tmp = 0;
    
    src = trim(src);
    while (src[i] != '\0') {
        if (src[i] == ' ' || src[i] == '\t' || src[i] == '\n')
            spaces += 1;
        i++;
    }
    i = 0;
    char **result = malloc(sizeof(char *) * (spaces));
    spaces = 0;
    while (src[i] != '\0') {
        if (src[i + 1] == '\0' || src[i] == ' ' || src[i] == '\t'|| src[i] == '\n') {
            result[spaces] = malloc(sizeof(char) * (i - tmp + 1));
            while (tmp < i) {
                result[spaces][j] = src[tmp];
                tmp+= 1;
                j += 1;
            }
            if (src[i + 1] == '\0') {
                result[spaces][j] = src[i];
                j += 1;
            }
            result[spaces][j] = '\0';
            spaces += 1;
            tmp += 1;
            i += 1;
            j = 0; 
        }
        i+= 1;
    }
    result[spaces] = NULL;
    return (result);
}