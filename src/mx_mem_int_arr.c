#include "pathfinder.h"

int* mx_mem_int_arr(int count) {
	int* array = ((int*)malloc(sizeof(int) * count));
	int j = 0;

	for(; j < count; j++) {
		array[j] = 0;
	}
	return array;
}
