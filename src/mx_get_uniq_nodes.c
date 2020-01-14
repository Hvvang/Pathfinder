#include "pathfinder.h"

char **mx_get_uniq_nodes(t_graf *graf, int size, int *uniq_islands) {
    char **str = (char **)malloc(sizeof(char *) * size * 2 + 1);
    int i;
    int j = 0;

    for (i = 0; i < size; i++) {
        str[j++] = mx_strdup(graf[i].node1);
        str[j++] = mx_strdup(graf[i].node2);
    }
    for (i = 0; str[i]; i++) {
        for (j = i + 1; str[j]; j++) {
            if (!mx_strcmp(str[i], str[j]) && mx_strcmp(str[i], "0")) {
                free(str[j]);
                str[j] = mx_strdup("0");
                (*uniq_islands)--;
            }
        }
    }
    return str;
}
