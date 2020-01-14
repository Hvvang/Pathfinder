#include "pathfinder.h"

bool mx_is_alphabetic(char c) {
    if ((c > 64 && c < 91) ||  (c > 96 && c < 123))
        return true;
    return false;
}
