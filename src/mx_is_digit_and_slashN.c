#include "pathfinder.h"

bool mx_is_digit_and_slashN(char *str) {
    if (str[mx_strlen(str) - 1] != '\n')
        return false;
    for (int i = 0; str[i]; i++) {
        if (str[i] < 48 || str[i] > 57) {
            if (i == mx_strlen(str) - 1  && str[i] == '\n')
                return true;
            return false;
        }
    }
    return true;
}
