#include <unistd.h> // sleep()
#include <stdio.h> // sprintf()
#include <stdlib.h> // malloc()
#include <string.h> // strcmp()
#include <limits.h> // INT_MAX
#include <stdint.h>
#include "log.h" // d()

const long megabyte = sizeof(char) * 1024 * 1024;
const char strategyBurn[] = "burn";

void holdMemory(long megabytes) {
	long chunk = sizeof(char) * megabytes * megabyte;

	char msg[512];
	sprintf(msg, "Holding %lu bytes", chunk);

	d(msg);

	char *address = (char *) malloc(chunk);

	memset(address, 0, chunk);

	while(1) sleep(10);

	sprintf(msg, "ptr: %d", *address);

	d(msg);
}

void burnAllMemory(long megabytes) {
	long chunk = megabytes * megabyte;

	//TOIMPROVE: will overflow before OOM if chunk size is too low
	int *addresses[100000];

	int addressesIndex = 0;

	char msg[512];
	sprintf(msg, "Burning all memory, %lu bytes each cycle", chunk);

	d(msg);

	while(1) {
		addresses[addressesIndex] = (int *) malloc(chunk);

		memset(addresses[addressesIndex], 0, chunk);

		addressesIndex++;
	}
}

void burn(char * strategy, long chunkByteSize) {
	if(strcmp(strategy, strategyBurn) == 0) {
		burnAllMemory(chunkByteSize);

		return;
	}

	holdMemory(chunkByteSize);
}

