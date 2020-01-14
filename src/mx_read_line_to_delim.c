#include "pathfinder.h"

char *mx_read_line_to_delim(char *content, int line, char delim) {
    char *res = NULL;
    int i = 0;
    int size = 0;

    while (i <= mx_strlen(content) && (content[i] != delim || line != 0)) {
        if (content[i] == delim)
            line--;
        if (line == 1 && content[i] != delim)
            size++;
        if (line)
            i++;
    }
    res = mx_strndup(content + i - size, size + 1);
    return res;
}
