void my_putchar(char c);

void my_putstr(char *str)
{
    int i = -1;

    while (str[++i] != '\0')
        my_putchar(str[i]);
}