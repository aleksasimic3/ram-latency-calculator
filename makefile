CC = g++
CFLAGS = -Wall -pedantic -Iinclude

SOURCE_DIR = src/
INCLUDE_DIR = include/
BIN_DIR = bin/

$(BIN_DIR)ddrLatency.exe: ddrLatency.o ramInfo.o
	$(CC) -o $(BIN_DIR)ddrLatency.exe ddrLatency.o ramInfo.o $(CFLAGS)

$(BIN_DIR)ddrLatencyShort.exe: ddrLatencyShort.o
	$(CC) -o $(BIN_DIR)ddrLatencyShort.exe ddrLatencyShort.o $(CFLAGS)

ddrLatency.o: $(SOURCE_DIR)ddrLatency.cpp $(INCLUDE_DIR)ramInfo.h
	$(CC) -c -o ddrLatency.o $(SOURCE_DIR)ddrLatency.cpp $(CFLAGS)

ramInfo.o: $(SOURCE_DIR)ramInfo.cpp $(INCLUDE_DIR)ramInfo.h
	$(CC) -c -o ramInfo.o $(SOURCE_DIR)ramInfo.cpp $(CFLAGS)

ddrLatencyShort.o: $(SOURCE_DIR)ddrLatencyShort.cpp
	$(CC) -c -o ddrLatencyShort.o $(SOURCE_DIR)ddrLatencyShort.cpp $(CFLAGS)