#include "pathfinder.h"

bool mx_is_digit(char c) {
	if (c < 48 || c > 57)
		return false;
	return true;
}
