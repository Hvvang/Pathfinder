#include "pathfinder.h"

static t_route *mx_new_route(int count, int start, int end) {
	t_route *route = (t_route*)malloc(sizeof(t_route));

	route->size = 1;
	route->count = count;
	route->route = mx_mem_int_arr(count);
	route->route[0] = end;
	route->route[1] = start;
	return route;
}

void mx_all_routes(t_graph *graph, int start, int end) {
	t_route *route = mx_new_route(graph->size, start, end);

	mx_backtrack(graph->matrix, graph->path_matrix, route, graph);
	free(route->route);
	route->route = NULL;
	free(route);
	route = NULL;
}
