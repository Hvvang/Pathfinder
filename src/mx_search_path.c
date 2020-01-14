#include "pathfinder.h"

static void floyd_warshall(int **path, int uniq_islands);

int **mx_search_path(int uniq_islands, int **adjacency_arr) {
    int **path = (int **)malloc(sizeof(int *) * uniq_islands + 1);

    for (int i = 0; i < uniq_islands; i++) {
        path[i] = (int *)malloc(sizeof(int) * uniq_islands);
        for (int j = 0; j < uniq_islands; j++) {
            path[i][j] = adjacency_arr[i][j];
        }
    }
    path[uniq_islands] = NULL;
    floyd_warshall(path, uniq_islands);
    return path;
}

static void floyd_warshall(int **path, int uniq_islands) {
    int min_dist = 0;

    for (int k = 0; k < uniq_islands; k++) {
        for (int i = 0; i < uniq_islands; i++) {
            for (int j = 0; j < uniq_islands; j++) {
                min_dist = path[i][k] + path[k][j];
                if (min_dist < path[i][j]) {
                    path[i][j] = min_dist;
                }
            }
        }
    }
}
