#include "pathfinder.h"

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		mx_printerr(INVLD_CMD_ARGS, NULL);
		exit(-1);
	}
	else {
  		mx_file_existing(argv[1]);
	}
	// system("leaks -q pathfinder");
	return 0;
}
