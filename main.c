#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "pkg/log.h"
#include "pkg/cfg.h"

const char *strategyBurn = "burn";
const char *strategyHold = "hold";

char * concat(char * a, char * b) {
	int aLength = strlen(a);
	int bLength = strlen(b);
	int resultLength = aLength + bLength + 1;

	char * result = malloc(sizeof(char) * resultLength);
	int resultIndex = 0;

	for(int currentIndex = 0; currentIndex < aLength; currentIndex++)
		result[resultIndex++] = a[currentIndex];

	for(int currentIndex = 0; currentIndex < bLength; currentIndex++)
		result[resultIndex++] = b[currentIndex];

	result[resultLength - 1] = '\0';

	return result;
}

void burn(char * strategy, int chunkByteSize) {
	if(strcmp(strategy, strategyBurn) == 0) {
		for(int i = 1; 1; i++) {
			malloc(chunkByteSize);
		}

		return;
	}

	malloc(chunkByteSize);

	while(1) {
		sleep(10);
	}
}

int main() {
	d("Loading config..");

	struct Config cfg = LoadConfig();

	d("Config loaded");

	printf("Delaying for %d seconds\n", cfg.delaySeconds);

	sleep(cfg.delaySeconds);

	d(concat("executing strategy ", cfg.strategy));

	burn(cfg.strategy, cfg.chunkByteSize);

	d("Burn success");
}
