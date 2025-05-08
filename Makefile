CC = gcc
CFLAGS = -Wall -g -std=c99
LDFLAGS =

SRCS = main.c graph.c
OBJS = $(SRCS:.c=.o)

TARGET = graph_tool

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c graph.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 