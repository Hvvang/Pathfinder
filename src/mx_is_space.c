#include "pathfinder.h"

bool mx_is_space(char c) {
    if (c == 32)
        return 1;
    if (c == '\t')
        return 1;
    if (c == '\n')
        return 1;
    if (c == '\v')
        return 1;
    if (c == '\f')
        return 1;
    if (c == '\r')
        return 1;
    return 0;
}
