CC=g++
CFLAGS=-c -Wall -std=c++11
INCLUDES=-Iinclude
PROGNAME=testFRC

.PHONY: clean

all: $(PROGNAME)
$(PROGNAME): test.o
	$(CC) $(INCLUDES) test.o -o $(PROGNAME).exe

test.o: test.cpp
	$(CC) $(CFLAGS) $(INCLUDES) test.cpp