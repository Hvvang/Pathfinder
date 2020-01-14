#include "pathfinder.h"

void mx_del_struct(t_file *file) {
    while (file) {
        t_file *temp = file;

        file = temp->next;
        mx_strdel(&temp->data);
        temp->next = NULL;
        free(temp);
    }
}
