#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_atoi(char *str) {
    int i = -1;
    int sign = 1;
    int result = 0;
    while (str[++i] != '\0') {
        if (str[i] == '-') {
            sign = -1;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            exit(84);
        }
    }
    return (result * sign);
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

int fibonacci(int n) {
    int i = 0;
    int j = 1;
    int tmp;
    while (n > 0) {
        tmp = i;
        i = j;
        j = tmp + j;
        n -= 1;
    }
    return (i);
}

void my_putstr(char *str) {
    int i = -1;
    while (str[++i] != '\0')
        write(1, &str[i], 1);
}

int main(int ac, char **av) {
    if (ac == 1) {
        return (0);
    }
    int tmp = my_atoi(av[1]);
    if (tmp < 0) {
        my_putstr("Error: fibonnacci is not defined for negative numbers.\n");
        return (1);
    }
    my_putstr(my_itoa(fibonacci(tmp - 1)));
    my_putstr("\n");
    return (0);
}