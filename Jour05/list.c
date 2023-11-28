#include "project.h"

t_album_list *create_album(char *artist, char *title, char *year){
    t_album_list *album = malloc(sizeof(t_album_list));
    album->artist = artist;
    album->title = title;
    album->year = year;
    album->next = NULL;
    return (album);
}

void push_back_album(t_album_list *list, t_album_list * album) {
    t_album_list *tmp = list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = album;
}

void my_free_list(t_album_list *list) {
    t_album_list *tmp = list;
    while (tmp != NULL) {
        t_album_list *tmp2 = tmp->next;
        free(tmp->artist);
        free(tmp->title);
        free(tmp->year);
        free(tmp);
        tmp = tmp2;
    }
    free(tmp);
}   

void print_album_list(t_album_list *list){
    t_album_list *tmp = list;
    while (tmp != NULL) {
        write(1, "\"", 1);
        write(1, tmp->title, my_strlen(tmp->title));
        write(1, "\" by \"", 6);
        write(1, tmp->artist, my_strlen(tmp->artist));
        write(1, "\" released in ", 15);
        write(1, tmp->year, my_strlen(tmp->year));
        write(1, ".\n", 2);   
        tmp = tmp->next;
    }
}