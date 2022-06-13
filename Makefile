BUILD_DIR=build

${BUILD_DIR}/burner:
	mkdir -p ${BUILD_DIR}
	gcc -o ${BUILD_DIR}/burner main.c

build: ${BUILD_DIR}/burner
