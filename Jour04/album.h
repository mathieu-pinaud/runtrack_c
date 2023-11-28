#ifndef ALBUM_H
#define ALBUM_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct album {
    char *artist;
    char *title;
    int year;
} t_album;

typedef struct album_list {
    char *artist;
    char *title;
    int year;
    struct album_list *next;
} t_album_list;

void print_album(t_album *album);
t_album_list *create_album(char *artist, char *title, int year);
void push_back_album(t_album_list *list, t_album_list *album);
void print_album_list(t_album_list *list);
char *my_itoa(int n);
int my_strlen(char *str);
void push_front_album(t_album_list **list, t_album_list *album);

#endif // ALBUM_H