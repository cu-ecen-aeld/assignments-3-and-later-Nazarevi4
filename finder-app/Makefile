# Author: Ivan Nazarenko
# Date: 06/09/23

ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	CC = aarch64-none-linux-gnu-gcc
else
	CC = gcc
endif

CFLAGS = -g -Wall

.PHONY: build

build: writer.c
	$(CC) $(CFLAGS) $^ -o writer

.PHONY: clean
clean:
	rm -f  writer *.o
