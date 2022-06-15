#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "log.h"
#include "cfg.h"

const int defaultDelay = 1;

const char * envGet(char * key, char * defaultValue) {
	char *value = getenv(key);

	if(!value) return defaultValue;

	return value;
}

int envGetInt(char * key, int defaultValue) {
	const char *value = envGet(key, "");

	int valueAsInt = atoi(value);

	if(valueAsInt == 0) return defaultValue;

	return valueAsInt;
}

struct Config LoadConfig() {
	char msg[512];
	struct Config cfg;

	d("Querying DELAY");
	cfg.delaySeconds = envGetInt("DELAY", defaultDelay);
	sprintf(msg, "Delay: %d", cfg.delaySeconds);
	d(msg);

	d("Querying CHUNK_MEGABYTE_SIZE");
	cfg.chunkByteSize = envGetInt("CHUNK_MEGABYTE_SIZE", 1);
	sprintf(msg, "Chunk size: %dMB", cfg.chunkByteSize);
	d(msg);

	d("Querying STRATEGY");
	const char * strategy = envGet("STRATEGY", "burn");

	cfg.strategy = malloc(sizeof(char) * strlen(strategy));

	strcpy(cfg.strategy, strategy);

	sprintf(msg, "Strategy: %s", cfg.strategy);
	d(msg);
	d("Config complete");

	return cfg;
}

