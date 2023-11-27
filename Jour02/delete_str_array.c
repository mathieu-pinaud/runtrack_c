#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void delete_str_array(char ***strs)
{
    int i = -1;
    while ((*strs)[++i] != NULL)
        free((*strs)[i]);
    free(*strs);
    *strs = NULL;
}