CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXEC = main

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ -O3

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -O3

clean:
	rm -f $(OBJS) $(EXEC)