#ifndef CFG_H
#define CFG_H "pkg/cfg.h"

struct Config {
	int delaySeconds;
	int chunkByteSize;
	char * strategy;
};

struct Config LoadConfig();

#endif
