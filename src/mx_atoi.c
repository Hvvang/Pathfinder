#include "pathfinder.h"

int mx_atoi(char *str) {
    int i = 0;
    int flag = 1;
    int res = 0;

    if (str[0] == '-') {
        flag = -1;
        i++;
    }
    while (mx_is_space(str[i]))
        return 0;
    while (str[i] && mx_is_digit(str[i])) {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res * flag;
}
