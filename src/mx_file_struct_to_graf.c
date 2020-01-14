#include "pathfinder.h"

static int is_zero_islands(t_file *temp, int bridges);

t_graf *mx_file_struct_to_graf(t_file *file,
int *uniq_islands, char ***uniq_nodes) {
    t_file *temp = file;
    t_graf *graf = NULL;
    int bridges = mx_count_bridges(temp);
    int i;

    if (is_zero_islands(temp, bridges) == 0)
        *uniq_islands = 0;
    else if (is_zero_islands(temp, bridges) == 1)
        *uniq_islands = -1;
    else {
        graf = malloc(sizeof(t_graf) * (bridges - 2));
        *uniq_islands = (bridges - 2) * 2;
        for (i = 0; i < bridges - 2; i++) {
            mx_parser_to_graf(&graf[i], temp->next);
            temp = temp->next;
        }
        *uniq_nodes = mx_get_uniq_nodes(graf, bridges - 2, uniq_islands);
    }
    return graf;
}

static int is_zero_islands(t_file *temp, int bridges) {
    if (mx_strcmp(temp->data, "0\n") == 0 && bridges == 2)
        return 0;
    else if (bridges == 2) {
        return 1;
    }
    return -1;
}
