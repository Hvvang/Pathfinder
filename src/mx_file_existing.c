#include "pathfinder.h"

void mx_file_existing(const char* file) {
	int descriptor = open(file, O_RDWR);

	if (descriptor < 0) {
		mx_printerr(FILE_EXIST, file);
		exit(-1);
	}
	else
		mx_content_validation(file);
}
