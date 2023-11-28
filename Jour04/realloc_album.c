#include "album.h"

t_album *realloc_album(t_album *albums,int size, int new_size){
    int i = 0;
    t_album *new_albums = malloc(sizeof(t_album) * new_size);
    while (i < size) {
        new_albums[i] = albums[i];
        i++;
    }
    free(albums);
    return (new_albums);
}