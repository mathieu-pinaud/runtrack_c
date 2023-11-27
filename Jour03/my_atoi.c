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
            return (0);
        }
    }
    return (result * sign);
}