all: expenses

CC = gcc
override CFLAGS += -g -pthread -lm -Iinclude

SRCS = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.h)

expenses: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

expenses-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f expenses expenses-debug
