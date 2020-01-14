#include "pathfinder.h"

t_file *mx_create_line(int line, char *data) {
    t_file *node = malloc(sizeof(t_file));

    node->line = line;
    node->data = mx_strdup(data);
    node->next = NULL;
    return node;
}
