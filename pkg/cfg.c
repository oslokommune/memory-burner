#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "log.h"
#include "cfg.h"

const int defaultDelay = 1;
const int kilobyte = 1024;
const int megabyte = 1024 * kilobyte;

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
	struct Config cfg;

	d("Querying DELAY");
	cfg.delaySeconds = envGetInt("DELAY", defaultDelay);

	d("Querying CHUNK_MEGABYTE_SIZE");
	cfg.chunkByteSize = envGetInt("CHUNK_MEGABYTE_SIZE", 1);
	cfg.chunkByteSize *= megabyte;

	d("Querying STRATEGY");
	const char * strategy = envGet("STRATEGY", "burn");

	cfg.strategy = malloc(sizeof(char) * strlen(strategy));

	strcpy(cfg.strategy, strategy);

	d("Config complete");

	return cfg;
}

