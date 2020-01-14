#include "pathfinder.h"

void mx_del_int_arr(int **arr) {
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}
