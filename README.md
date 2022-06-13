# Memory burner

# Why

To reproduce an issue where a node in a Kubernetes cluster got terminated due
to an application using all available memory.

# How

`while(true) malloc(1MB)`, pretty much.

Try not to run this locally. Use the docker image inside docker to test it out.

```shell
docker run --rm -e DELAY=5 ghcr.io/oslokommune/memory-burner:v0.0.2
```

where `DELAY` determines how many seconds from execution to the actual memory
burn begins. Default is 1 second.
