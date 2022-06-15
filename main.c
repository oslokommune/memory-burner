#include <stdio.h> // sprintf()
#include <unistd.h> // sleep()
#include "pkg/log.h"
#include "pkg/cfg.h"
#include "pkg/burn.h"

int main() {
	char msg[100];
	struct Config cfg;

	d("Loading config");

	cfg = LoadConfig();

	d("Config loaded");

	sprintf(msg, "Delaying for %d seconds", cfg.delaySeconds);
	d(msg);

	sleep(cfg.delaySeconds);

	sprintf(msg, "Executing strategy %s", cfg.strategy);
	d(msg);

	burn(cfg.strategy, cfg.chunkByteSize);

	d("Burn success");
}
