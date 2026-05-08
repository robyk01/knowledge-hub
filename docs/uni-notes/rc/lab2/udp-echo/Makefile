CC = gcc
CFLAGS = -Wall

all: compile print-end

compile: servUdp cliUdp

servUdp: servUdp.c
	$(CC) $(CFLAGS) servUdp.c -o servUdp

cliUdp: cliUdp.c
	$(CC) $(CFLAGS) cliUdp.c -o cliUdp

clean:
	rm -f servUdp cliUdp

print-end:
	@echo "** ALL FILES COMPILED **"

test-server:
	./servUdp

test-client:
	./cliUdp 127.0.0.1 2728
