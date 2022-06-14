FROM gcc:12.1.0 AS build

WORKDIR /app

COPY pkg ./pkg
COPY main.c .
COPY Makefile .

RUN make build

CMD ["/app/build/burner"]
