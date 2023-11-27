#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void strtolower(char *str)
{
    int i = -1;
    while (str[++i] != '\0')
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
}

void strtoupper(char *str)
{
    int i = -1;
    while (str[++i] != '\0')
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}

void my_putstr(char *str)
{
    int i = -1;
    while (str[++i] != '\0')
        write(1, &str[i], 1);
    write(1, "\n", 1);
}

void func_to_array(char **strs, void (*fun)(char *))
{
    int i = 1;
    while (strs[++i] != NULL)
        fun(strs[i]);
}

int main(int ac, char **argv)
{
    ac +=1;
    func_to_array(argv, &strtolower);
    func_to_array(argv, &my_putstr);
}