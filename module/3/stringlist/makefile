CC = g++  
prog: main.o stringlist.o 
	$(CC) main.o stringlist.o -o strings 
main.o: main.cpp stringlist.h 
	$(CC) -c main.cpp 
stringlist.o: stringlist.cpp stringlist.h 
	$(CC) -c stringlist.cpp 
