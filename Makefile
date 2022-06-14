BUILD_DIR=build

${BUILD_DIR}/burner:
	mkdir -p ${BUILD_DIR}
	gcc -o ${BUILD_DIR}/burner pkg/cfg.c pkg/log.c main.c

build: ${BUILD_DIR}/burner

run:
	docker run \
		--rm \
		`docker build -q .`

clean:
	rm -r ./build/
