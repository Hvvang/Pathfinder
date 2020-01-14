#include "pathfinder.h"

void mx_push_line(t_file **file, int line_index, char *data) {
    t_file *line = mx_create_line(line_index, data);
    t_file *temp = *file;

    if (*file == NULL) {
        *file = line;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = line;
}
