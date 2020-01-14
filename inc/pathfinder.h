#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "./libmx/inc/libmx.h"


//***************************** Utils pack *******************************

#define DELIM_BLOCK "========================================\n"
#define NEW_LINE "\n"
#define EMPTY_LINE ""
#define PATH "Path: "
#define ROUTE "Route: "
#define EQUALITY " = "
#define PLUS " + "
#define ARROW " -> "
#define DISTANCE "Distance: "

typedef struct s_file{
	int line;
	char *data;
	struct s_file *next;

} t_file;

typedef enum e_error {
    INVLD_CMD_ARGS,
    FILE_EXIST,
    FILE_EMPTY,
    INVLD_LINE,
    INVLD_NUM_ISLDS
} t_error;

typedef struct s_graf {
	char *node1;
	char *node2;
	int dist;

} t_graf;

typedef struct s_path {
	char *node1;
	char *node2;
	char **route;
	char **dist;

} t_path;

typedef struct s_graph
{
	int size;
	int** matrix;
	int** path_matrix;
	char** uniq;
} t_graph;

typedef struct s_route
{
    int size;
    int *route;
    int count;
} t_route;

void mx_printerr(t_error err, const char *data);
void mx_printerror(const char *error);
void mx_file_existing(const char* file);
void mx_content_validation(const char *file);
void mx_del_str_arr(char **arr);
bool mx_is_digit_and_slashN(char *str);
bool mx_is_digit(char c);
int mx_atoi(char *str);
bool mx_is_space(char c);
void mx_parser_to_graf(t_graf *dest, t_file *src);
t_file *mx_parse_file_to_struct(char *content);
t_file *mx_create_line(int line, char *data);
char *mx_read_line_to_delim(char *content, int line, char delim);
void mx_push_line(t_file **file, int line_index, char *data);
void mx_del_struct(t_file *file);
int mx_check_lines(t_file *file);
bool mx_is_alphabetic(char c);
int mx_count_bridges(t_file *file);
t_graf *mx_file_struct_to_graf(t_file *file,
int *uniq_islands, char ***uniq_nodes);
char **mx_get_uniq_nodes(t_graf *graf, int size, int *uniq_islands);
void mx_del_graf(t_graf *graf, int size);
bool mx_amount_islands_validation(t_file *file_struct, int uniq_islands);
void mx_get_adj_arr(t_graf *graf, int graf_size, char **nodes, int amount);
int **mx_search_path(int uniq_islands, int **adjacency_arr);
void mx_del_int_arr(int **arr);
t_graph *mx_new_graph(int **matrix, int **path_matrix, int size, char **uniq);
void mx_all_routes(t_graph *graph, int start, int end);
void mx_backtrack(int **matrix, int **matrix_path, t_route *route, t_graph *g);
void mx_all_routes(t_graph *graph, int start, int end);
int* mx_mem_int_arr(int count);

//-----------------------------------------------------------------------

#endif
