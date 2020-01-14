#include "pathfinder.h"

static int count_lines(char *content);

t_file *mx_parse_file_to_struct(char *content) {
    int amount_of_lines = count_lines(content);
    t_file *file = NULL;
    int i;

    for (i = 0; i < amount_of_lines + 1 ; i++) {
        char *line = mx_read_line_to_delim(content, i + 1, '\n');

        mx_push_line(&file, i + 1, line);
        mx_strdel(&line);
    }
    mx_strdel(&content);
    return file;
}

static int count_lines(char *content) {
    int lines = 0;
    int i;

    for (i = 0; content[i]; i++) {
        if (content[i] == '\n')
            lines++;
    }
    return lines;
}
