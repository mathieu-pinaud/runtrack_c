#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char *src)
{
    int i = -1;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[++i] != '\0')
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int main(void)
{
    char *str = "Hello World!";
    char *str2 = my_strdup(str);

    printf("%s\n", str2);
    free(str2);
    return (0);
}