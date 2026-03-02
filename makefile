CC = g++
CFLAGS = -Wall -pedantic -Iinclude

SOURCE_DIR = src/
INCLUDE_DIR = include/
BIN_DIR = bin/

$(BIN_DIR)ddrLatency.exe: ddrLatency.o ramInfo.o
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN_DIR)ddrLatencyShort.exe: ddrLatencyShort.o
	$(CC) -o $@ $^ $(CFLAGS)

ddrLatency.o: $(SOURCE_DIR)ddrLatency.cpp $(INCLUDE_DIR)ramInfo.h
	$(CC) -c -o $@ $< $(CFLAGS)

ramInfo.o: $(SOURCE_DIR)ramInfo.cpp $(INCLUDE_DIR)ramInfo.h
	$(CC) -c -o $@ $< $(CFLAGS)

ddrLatencyShort.o: $(SOURCE_DIR)ddrLatencyShort.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)