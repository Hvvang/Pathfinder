#include "pathfinder.h"

t_graph *mx_new_graph(int **matrix, int **path_matrix, int size, char **uniq) {
	t_graph *graph = (t_graph*)malloc(sizeof(t_graph));

	graph->size = size;
	graph->matrix = matrix;
	graph->path_matrix = path_matrix;
	graph->uniq = uniq;
	return graph;
}
