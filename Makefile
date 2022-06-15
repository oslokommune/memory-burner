BUILD_DIR=build

${BUILD_DIR}/burner:
	mkdir -p ${BUILD_DIR}
	gcc -o ${BUILD_DIR}/burner pkg/cfg.c pkg/log.c pkg/burn.c main.c

build: ${BUILD_DIR}/burner

run:
	docker run \
		-e DELAY=2 \
		-e CHUNK_MEGABYTE_SIZE=500 \
		-e STRATEGY=hold \
		--rm \
		`docker build -q .`

clean:
	rm -r ./build/
