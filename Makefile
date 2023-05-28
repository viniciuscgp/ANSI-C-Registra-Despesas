all: expenses

CC = gcc
override CFLAGS += -g -Wno-everything -pthread -lm

SRCS = *.c
HEADERS = *.h

expenses: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

expenses-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f expenses expenses-debug