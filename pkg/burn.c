#include <unistd.h> // sleep()
#include <stdio.h> // sprintf()
#include <stdlib.h> // malloc()
#include <string.h> // strcmp()
#include "log.h" // d()

const long megabyte = sizeof(char) * 1024;
const char strategyBurn[] = "burn";

void holdMemory(long megabytes) {
	malloc(megabytes * megabyte);

	while(1) sleep(10);
}

void burnAllMemory(long megabytes) {
	while(1) malloc(megabytes * megabyte);
}

void burn(char * strategy, long chunkByteSize) {
	char msg[512];
	sprintf(msg, "Strategy: %s\nChunk size: %lu\n", strategy, chunkByteSize);

	d(msg);

	if(strcmp(strategy, strategyBurn) == 0) {
		burnAllMemory(chunkByteSize);

		return;
	}

	holdMemory(chunkByteSize);
}

