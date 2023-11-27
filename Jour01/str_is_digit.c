int char_is_digit(char c);

int str_is_digit(char *str)
{
    int i = -1;

    while (str[++i] != '\0')
        if (!char_is_digit(str[i]))
            return (0);
    return (1);
}