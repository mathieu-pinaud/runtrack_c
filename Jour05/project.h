#ifndef PROJET_H
#define PROJET_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>


typedef struct album_list {
    char *artist;
    char *title;
    char *year;
    struct album_list *next;
} t_album_list;

t_album_list *create_album(char *artist, char *title, char *year);
t_album_list *file_to_list(char *filename);
void sort_album_by(t_album_list **list, int (*fun)(t_album_list *, t_album_list *));
int album_sort_by_year(t_album_list *album1, t_album_list *album2);
int album_sort_by_title(t_album_list *album1, t_album_list *album2);
int album_sort_by_artist(t_album_list *album1, t_album_list *album2);
void push_back_album(t_album_list *list, t_album_list * album);
void my_free_list(t_album_list *list);
void print_album_list(t_album_list *list);
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *str);
char **split(char *src, char c);
void my_free_array(char **array);

#endif /* !PROJET_H */