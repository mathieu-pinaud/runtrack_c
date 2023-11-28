#include "album.h"

void push_back_album(t_album_list *list, t_album_list * album) {
    t_album_list *tmp = list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = album;
}