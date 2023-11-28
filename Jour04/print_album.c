#include "album.h"

int my_strlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_itoa(int n) {
    char *str;
    int len = 0;
    int tmp = n;
    int sign = 1;
    while (tmp != 0) {
        tmp /= 10;
        len += 1;
    }
    if (n < 0) {
        sign = -1;
        len += 1;
    }
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    while (len > 0) {
        str[len - 1] = (n % 10) * sign + '0';
        n /= 10;
        len -= 1;
    }
    if (sign == -1)
        str[0] = '-';
    return (str);
}

void print_album(t_album *album) {
    write(1, "\"", 1);
    write(1, album->title, my_strlen(album->title));
    write(1, "\" by \"", 6);
    write(1, album->artist, my_strlen(album->artist));
    write(1, "\" released in ", 15);
    char *year = my_itoa(album->year);
    write(1, year, my_strlen(year));
    write(1, ".\n", 2);   
}