#include "project.h"

bool error_handling(int argc, char **argv)
{
    if (argc != 3) {
        write(2, "Incorrect format.", 17);
        return (false);
    }
    
    if (open(argv[1], O_RDONLY) == -1) {
        write(2, "File not found.", 15);
        return (false);
    }

    if (my_strcmp(argv[2], "artist") != 0 && my_strcmp(argv[2], "title") != 0 && my_strcmp(argv[2], "year") != 0) {
        write(2, "Sort method does not exist.", 27);
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    if (!error_handling(argc, argv))
        return (1);
    t_album_list *list = file_to_list(argv[1]);
    if (list == NULL) {
        write(2, "Incorrect format.", 17);
        return (1);
    }
    char *sort_method = argv[2];
    switch (sort_method[0]) {
        case 'a':
            sort_album_by(&list, album_sort_by_artist);
            break;
        case 't':
            sort_album_by(&list, album_sort_by_title);
            break;
        case 'y':
            sort_album_by(&list, album_sort_by_year);
            break;
    }
    print_album_list(list);
    my_free_list(list);
    return (0);
}