#include "pathfinder.h"

static int **parse_arr(t_graf *graf, int amount, int graf_size, char **nodes);
static void free_alloc(int **adjacency_arr, char **nodes, char **uniq_nodes);
static void get_path(int amount, int **adj_arr, char **uniq_nodes);

void mx_get_adj_arr(t_graf *graf, int graf_size, char **nodes, int amount) {
    int **adjacency_arr;
    char **uniq_nodes = (char **)malloc(sizeof(char *) * amount + 1);
    int j = 0;
    int i = 0;

    for (i = 0; nodes[j]; j++) {
        if (mx_strcmp(nodes[j], "0") != 0 || nodes[j] == NULL)
            uniq_nodes[i++] = mx_strdup(nodes[j]);
    }
    uniq_nodes[amount] = NULL;
    adjacency_arr = parse_arr(graf, amount, graf_size, uniq_nodes);
    get_path(amount, adjacency_arr, uniq_nodes);
    free_alloc(adjacency_arr, nodes, uniq_nodes);
}

static int **parse_arr(t_graf *graf, int amount, int graf_size, char **nodes) {
    t_graf *temp = graf;
    int **adjacency_arr = (int **)malloc(sizeof(int *) * amount + 1);

    for (int i = 0; i < amount; i++) {
        adjacency_arr[i] = (int *)malloc(sizeof(int) * amount);
        for (int j = 0; j < amount; j++) {
            adjacency_arr[i][j] = 10232323;
            for (int k = 0; k < graf_size; k++) {
                if ((!mx_strcmp(temp[k].node1, nodes[i])
                     && !mx_strcmp(temp[k].node2, nodes[j]))
                     || (!mx_strcmp(temp[k].node1, nodes[j])
                     && !mx_strcmp(temp[k].node2, nodes[i]))) {
                        adjacency_arr[i][j] = temp[k].dist;
                }
            }
        }
        adjacency_arr[i][i] = 0;
    }
    adjacency_arr[amount] = NULL;
    return adjacency_arr;
}

static void get_path(int amount, int **adj_arr, char **uniq_nodes) {
    int **path = mx_search_path(amount, adj_arr);
    t_graph *graph = mx_new_graph(adj_arr, path, amount, uniq_nodes);
    int i;
    int j;

    for (i = 0; i < amount; i++) {
        for (j = 0; j < amount; j++) {
            if (i < j) {
                mx_all_routes(graph, i, j);
            }
        }
    }
    mx_del_int_arr(path);
    free(graph);
    graph=NULL;
}

static void free_alloc(int **adjacency_arr, char **nodes, char **uniq_nodes) {
    mx_del_int_arr(adjacency_arr);
    mx_del_str_arr(nodes);
    mx_del_str_arr(uniq_nodes);
}
