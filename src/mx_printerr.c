#include "pathfinder.h"

static void file_exist(const char *data);
static void file_empty(const char *data);
static void invalid_line(const char *data);

void mx_printerr(t_error err, const char *data) {
    switch (err) {
        case INVLD_CMD_ARGS:
            mx_printerror("usage: ./pathfinder [filename]\n");
			break;
        case FILE_EXIST:
            file_exist(data);
			break;
        case FILE_EMPTY:
            file_empty(data);
			break;
        case INVLD_LINE:
            invalid_line(data);
			break;
        case INVLD_NUM_ISLDS:
            mx_printerror("error: invalid number of islands\n");
			break;
    }
}

static void file_exist(const char *data) {
    mx_printerror("error: file ");
    mx_printerror(data);
    mx_printerror(" does not exist\n");
}

static void file_empty(const char *data) {
    mx_printerror("error: file ");
    mx_printerror(data);
    mx_printerror(" is empty\n");
}

static void invalid_line(const char *data) {
    mx_printerror("error: line ");
    mx_printerror(data);
    mx_printerror(" is not valid\n");
}
