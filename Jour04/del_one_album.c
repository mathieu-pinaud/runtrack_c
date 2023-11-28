#include "album.h"

void album_del_one(t_album_list **list, t_album_list *elem) {
    t_album_list *tmp = *list;
    if (tmp == elem) {
        *list = tmp->next;
        free(tmp);
        return;
    }
    while (tmp->next != NULL) {
        if (tmp->next == elem) {
            tmp->next = tmp->next->next;
            free(elem);
            return;
        }
        tmp = tmp->next;
    }
}
