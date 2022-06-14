#include <stdio.h>

void d(char * msg) {
	printf("[DEBUG] %s\n", msg);

	fflush(stdout);
}
