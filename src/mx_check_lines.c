#include "pathfinder.h"

static bool check_first_line(char *str);
static bool check_other_line(char *str);
static bool check_desh_and_coma(char *str);
static bool check_island(char **str);

int mx_check_lines(t_file *file) {
    t_file *temp = file;

    if (temp->line == 1)
        if (!check_first_line(temp->data))
            return temp->line;
    while (temp->next) {
        temp = temp->next;
        if (!temp->next && mx_strcmp(temp->data, "") == 0)
            return -1;
        if (!check_desh_and_coma(temp->data))
            return temp->line;
        if (!check_other_line(temp->data))
            return temp->line;
    }
    return -1;
}

static bool check_first_line(char *str) {
    if (!mx_is_digit_and_slashN(str) || mx_strcmp(str, "") == 0) {
        return false;
    }
    return true;
}

static bool check_other_line(char *str) {
    char **arr = mx_strsplit(str, ',');

    if (arr[0] && arr[1]) {
        char **islands = mx_strsplit(arr[0], '-');
        bool checker = check_first_line(arr[1]);

        if (checker && islands[0] && islands[1])
            checker = check_island(islands);
        else
            checker = false;
        mx_del_str_arr(islands);
        mx_del_str_arr(arr);
        return checker;
    }
    else {
        mx_del_str_arr(arr);
        return false;
    }
}

static bool check_desh_and_coma(char *str) {
    int i;
    int desh = 1;
    int coma = 1;

    for (i = 0; i < mx_strlen(str); i++) {
        if (str[i] == '-') {
            if (coma != 1)
                return false;
            desh--;
        }
        if (str[i] == ',') {
            if (desh != 0)
                return false;
            coma--;
        }
    }
    if (desh != 0 || coma != 0)
        return false;
    return true;
}

static bool check_island(char **str) {
    int i;
    int j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < mx_strlen(str[i]); j++) {
            if (!mx_is_alphabetic(str[i][j]))
                return false;
        }
    }
    return true;
}
