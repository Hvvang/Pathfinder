#include "pathfinder.h"

static int check_neighboor(int n, int** matrix,
int** matrix_path, t_route *route);
static void print_distance(t_route *route, int **path_matrix);
static void mx_print_route(t_route *route, int **matrix_path, t_graph *grph);
static void full_route(t_graph *graph, t_route *route);

void mx_backtrack(int **matrix, int **matrix_path,
t_route *route, t_graph *g) {
	int count = route->count;

	if (route->route[route->size] == route->route[0]) {
		mx_print_route(route, matrix_path, g);
		return ;
	}
	else {
		for (int i = 0; i < count; i++) {
			if(check_neighboor(i, matrix, matrix_path, route)) {
				if (route->size < route->count) {
					route->size++;
					route->route[route->size] = i;
				}
				mx_backtrack(matrix, matrix_path, route, g);
				if(route->size > 1)
					route->size--;
			}
		}
	}
}

static int check_neighboor(int n, int** matrix,
int** matrix_path, t_route *route) {
	int i = route->route[route->size];
	int j = route->route[0];

	if (i != n) {
		if (matrix[i][n] == matrix_path[j][i] - matrix_path[j][n])
			return 1;
	}
	return 0;
}

static void full_route(t_graph *graph, t_route *route) {
    for (int i = 1; i <= route->size; i++) {
    	mx_printstr(graph->uniq[route->route[i]]);
    	if (i < route->size)
    		mx_printstr(ARROW);
    	else
    		mx_printstr(EMPTY_LINE);
    }
}

static void mx_print_route(t_route *route, int **matrix_path, t_graph *grph) {
    mx_printstr(DELIM_BLOCK);
    mx_printstr(PATH);
    mx_printstr(grph->uniq[route->route[1]]);
    mx_printstr(ARROW);
    mx_printstr(grph->uniq[route->route[0]]);
    mx_printstr(NEW_LINE);
    mx_printstr(ROUTE);
    full_route(grph, route);
    print_distance(route, matrix_path);
    mx_printstr(NEW_LINE);
    mx_printstr(DELIM_BLOCK);
}

static void print_distance(t_route *route, int **path_matrix) {
    int sum = 0;
    int n = route->size;

    mx_printstr(NEW_LINE);
    mx_printstr(DISTANCE);
    if (n == 2)
        mx_printint(path_matrix[route->route[n]][route->route[n - 1]]);
    else {
        for (int i = 1; i < n; i++) {
            mx_printint(path_matrix[route->route[i]][route->route[i + 1]]);
            sum += path_matrix[route->route[i]][route->route[i + 1]];
            if (i + 1 < n)
            	mx_printstr(PLUS);
            else
            	mx_printstr(EMPTY_LINE);
        }
        mx_printstr(EQUALITY);
        mx_printint(sum);
    }
}
