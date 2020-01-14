#include "pathfinder.h"

int mx_count_bridges(t_file *file) {
    t_file *temp = file;
    int count = 0;

    while (temp != NULL && temp->next) {
        temp = temp->next;
        count++;
    }
    if (count)
        count++;
    return count;
}
