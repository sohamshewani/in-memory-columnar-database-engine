CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c11
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)
TEST_OBJS=$(wildcard test/*.c:.c=.o)
EXECUTABLE=bin/inmemorydb

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run-tests: $(TEST_OBJS)
	./bin/inmemorydb_test

.PHONY: clean test

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(EXECUTABLE)
