#include "pathfinder.h"

static void is_content(char *content, const char *file);
static void is_valid_islands(t_file *file_struct, t_graf *graf,
int uniq_islands, char **uniq_nodes);
static void is_valid_line(t_file *file_struct);

void mx_content_validation(const char *file) {
	char *content =  mx_file_to_str(file);
	t_file *file_struct;
	t_graf *graf;
	int uniq_islands;
	char **uniq_nodes;

	is_content(content, file);
	file_struct = mx_parse_file_to_struct(content);
	is_valid_line(file_struct);
	graf = mx_file_struct_to_graf(file_struct, &uniq_islands, &uniq_nodes);
	is_valid_islands(file_struct, graf, uniq_islands, uniq_nodes);

	mx_get_adj_arr(graf, mx_count_bridges(file_struct) - 2, uniq_nodes, uniq_islands);
	mx_del_graf(graf, mx_count_bridges(file_struct) - 2);
	mx_del_struct(file_struct);
}

static void is_content(char *content, const char *file) {
	if (content == NULL) {
		mx_printerr(FILE_EMPTY, file);
		exit(-1);
	}
}

static void is_valid_line(t_file *file_struct) {
	if (mx_check_lines(file_struct) > -1) {
		char *index = mx_itoa(mx_check_lines(file_struct));

		mx_printerr(INVLD_LINE, index);
		mx_strdel(&index);
		mx_del_struct(file_struct);
		exit(-1);
	}
}

static void is_valid_islands(t_file *file_struct, t_graf *graf,
int uniq_islands, char **uniq_nodes) {
	if (uniq_islands == 0) {
		mx_del_graf(graf, mx_count_bridges(file_struct) - 2);
		mx_del_struct(file_struct);
		exit(0);
	}
	else if (uniq_islands == -1) {
		mx_printerr(INVLD_NUM_ISLDS, NULL);
		mx_del_graf(graf, mx_count_bridges(file_struct) - 2);
		mx_del_struct(file_struct);
		exit(-1);
	}
	else if (!mx_amount_islands_validation(file_struct, uniq_islands)) {
		mx_del_str_arr(uniq_nodes);
		mx_del_graf(graf, mx_count_bridges(file_struct) - 2);
		mx_del_struct(file_struct);
		exit(-1);
	}
}
