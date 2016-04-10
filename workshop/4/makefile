CC = g++ 
prog: main.o zoo.o
	$(CC) main.o zoo.o animal.o stock.o -o zooProgram
main.o: main.cpp zoo.h
	$(CC) -c main.cpp
zoo.o: zoo.cpp zoo.h stock.o vector.h
	$(CC) -c zoo.cpp 
stock.o: stock.cpp stock.h animal.o
	$(CC) -c stock.cpp
animal.o: animal.cpp animal.h 
	$(CC) -c animal.cpp
