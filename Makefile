CC = g++
CPPFLAGS =	-std=c++11
CPPLINK = -lstdc++
SRC_DIR = src
CFLAGS =  -c -Wall -I$(SRC_DIR)

all: lib/SniffleString.o

lib/SniffleString.o: $(SRC_DIR)/SniffleString.cpp; $(CC) $(CPPFLAGS) $(CFLAGS) src/SniffleString.cpp -o $@