#include "project.h"

t_album_list *file_to_list(char *file_name){
    int fd = open(file_name, O_RDONLY);
    t_album_list *list = NULL;
    int i = 0;
    char buffer[4096];

    if (fd == -1)
        return (NULL);
    int size = read(fd, buffer, 4096);
    if (size == -1)
        return (NULL);
    buffer[size] = '\0';
    char **lines = split(buffer, '\n');
    while (lines[i] != NULL) {
        char **album = split(lines[i], ',');
        if (album[0] != NULL && album[1] != NULL && album[2] != NULL) {
            t_album_list *new_album = create_album(album[0], album[1], album[2]);
            if (list == NULL)
                list = new_album;
            else
                push_back_album(list, new_album);
        } else return (NULL);
        free(album);
        i += 1;
    }
    my_free_array(lines);
    close(fd);
    return (list);
}