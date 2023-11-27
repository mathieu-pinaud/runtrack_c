#include <stdlib.h>
#include <unistd.h>

char *itoa_hex(int n) {
    char *str;
    int len = 0;
    int tmp = n;
    int sign = 1;
    while (tmp != 0) {
        tmp /= 16;
        len += 1;
    }
    if (n < 0) {
        sign = -1;
        len += 1;
    }
    str = malloc(sizeof(char) * (len + 1) * 4);
    str[len] = '\0';
    while (len > 0) {
        if (n % 16 < 10)
            str[len - 1] = (n % 16) * sign + '0';
        else
            str[len - 1] = (n % 16) * sign + 'A' - 10;
        n /= 16;
        len -= 1;
    }
    if (sign == -1)
        str[0] = '-';
    return (str);
}

void my_putstr(char *str) {
    int i = -1;
    while (str[++i] != '\0')
        write(1, &str[i], 1);
}

int main(void) {
    my_putstr(itoa_hex(45));
    my_putstr("\n");
    return (0);
}