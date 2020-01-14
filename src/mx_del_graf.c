#include "pathfinder.h"

void mx_del_graf(t_graf *graf, int size) {
    int i;

    for (i = 0; i < size; i++) {
        mx_strdel(&graf[i].node1);
        mx_strdel(&graf[i].node2);
    }
    free(graf);
    graf = NULL;
}
