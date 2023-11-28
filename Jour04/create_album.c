#include "album.h"

t_album_list *create_album(char *artist, char *title, int year){
    t_album_list *album = malloc(sizeof(t_album_list));
    album->artist = artist;
    album->title = title;
    album->year = year;
    album->next = NULL;
    return (album);
}

void print_album_list(t_album_list *list){
    t_album_list *tmp = list;
    while (tmp != NULL) {
        write(1, "\"", 1);
        write(1, tmp->title, my_strlen(tmp->title));
        write(1, "\" by \"", 6);
        write(1, tmp->artist, my_strlen(tmp->artist));
        write(1, "\" released in ", 15);
        char *year = my_itoa(tmp->year);
        write(1, year, my_strlen(year));
        write(1, ".\n", 2);   
        tmp = tmp->next;
    }
}