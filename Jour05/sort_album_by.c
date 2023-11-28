#include "project.h"
#include <stdbool.h>

int album_sort_by_year(t_album_list *album1, t_album_list *album2) {
    if (album1->year > album2->year)
        return (1);
    else if (album1->year < album2->year)
        return (-1);
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
        i +=1;
    }
    return (0);
}

int album_sort_by_title(t_album_list *album1, t_album_list *album2) {
    return (my_strcmp(album1->title, album2->title));
}

int album_sort_by_artist(t_album_list *album1, t_album_list *album2) {
    return (my_strcmp(album1->artist, album2->artist));
}

void sort_album_by(t_album_list **list, int (*fun)(t_album_list *, t_album_list *)) {
    bool sorted = true;
    while (sorted) {
        sorted = false;
        t_album_list **tmp = list;
        while ((*tmp)->next != NULL) {
            if (fun((*tmp), (*tmp)->next) > 0) {
                t_album_list *tmp2 = (*tmp)->next;
                (*tmp)->next = tmp2->next;
                tmp2->next = *tmp;
                *tmp = tmp2;
                sorted = true;
            }
            tmp = &(*tmp)->next;
        }
    }
}