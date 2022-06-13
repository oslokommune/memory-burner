#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int defaultDelay = 1;
const int kilobyte = 1024;
const int megabyte = 1024 * kilobyte;

int main() {
	printf("Loading config..\n");

	char *burnDelayAsString = getenv("DELAY");

	if(!burnDelayAsString) {
		burnDelayAsString = "n/a";
	}

	int burnDelay = atoi(burnDelayAsString);

	if(burnDelay == 0) {
		burnDelay = defaultDelay;
	}

	printf("Delaying for %d seconds\n", burnDelay);

	fflush(stdout);

	sleep(burnDelay);

	for(int i = 1; 1; i++) {
		malloc(1 * megabyte);
	}

	printf("Burn success\n");
}
