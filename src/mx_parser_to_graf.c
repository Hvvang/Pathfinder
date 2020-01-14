#include "pathfinder.h"

void mx_parser_to_graf(t_graf *dest, t_file *src) {
    char **data = mx_strsplit(src->data, ',');
    char **nodes = mx_strsplit(data[0], '-');
    int dist = mx_atoi(data[1]);

    dest->node1 = mx_strdup(nodes[0]);
    dest->node2 = mx_strdup(nodes[1]);
    dest->dist = dist;
    mx_del_str_arr(nodes);
    mx_del_str_arr(data);

}
