#include "pathfinder.h"

bool mx_amount_islands_validation(t_file *file_struct, int uniq_islands) {
    if (mx_atoi(file_struct->data) != uniq_islands) {
        mx_printerr(INVLD_NUM_ISLDS, NULL);
        return false;
    }
    return true;
}
