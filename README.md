<p align="center">
  <img width="256" src="https://i.kym-cdn.com/photos/images/original/000/000/130/disaster-girl.jpg" />
  <h3 align="center">Memory Burner</h3>
</p>

## Why

To reproduce an issue where a node in a Kubernetes cluster got terminated due
to an application using all available memory.

## How

`while(true) malloc(1MB)`, pretty much.

Try not to run this locally. Use the docker image inside docker to test it out.

```shell
docker run --rm \
	-e DELAY=5 \
	-e STRATEGY=burn \
	-e CHUNK_MEGABYTE_SIZE=
	ghcr.io/oslokommune/memory-burner:v0.0.5
```

## Configuration

Memory burner is configured using environment variables. The following
configuration parameters are available:

### DELAY

determines how many seconds from execution to the actual memory burn begins.
Default is 1 second.

### STRATEGY

Determines if the app should just hold on to the memory, i.e.: `hold`, or if it
should try to burn as much memory as possible, i.e.: `burn`.

### CHUNK_MEGABYTE_SIZE

Determines how many megabytes of memory it should hold on to in the `hold`
strategy. Or how many megabytes of memory it should burn each CPU cycle for the
`burn` strategy.
