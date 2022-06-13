#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const int defaultDelay = 1;
const int kilobyte = 1024;
const int megabyte = 1024 * kilobyte;

const char *strategyBurn = "burn";
const char *strategyHold = "hold";

struct Config {
	int delaySeconds;
	int chunkByteSize;
	char * strategy;
};

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

struct Config loadConfig() {
	struct Config cfg;

	cfg.delaySeconds = envGetInt("DELAY", 1);
	cfg.chunkByteSize = envGetInt("CHUNK_MEGABYTE_SIZE", 1 * megabyte);
	strcpy(cfg.strategy, envGet("STRATEGY", "burn"));

	return cfg;
}

int main() {
	printf("Loading config..\n");

	struct Config cfg = loadConfig();

	printf("Delaying for %d seconds\n", cfg.delaySeconds);

	fflush(stdout);

	sleep(cfg.delaySeconds);

	if(strcmp(cfg.strategy, strategyBurn)) {
		for(int i = 1; 1; i++) {
			malloc(cfg.chunkByteSize);
		}

		return 0;
	}

	malloc(cfg.chunkByteSize);

	while(1) {
		sleep(10);
	}

	printf("Burn success\n");
}
