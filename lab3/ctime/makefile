output: main.o ctime.o
	g++ main.o ctime.o -o output
main.o: main.cpp
	g++ -c main.cpp
ctime.o: ctime.cpp ctime.h
	g++ -c ctime.cpp
clean:
	rm *.o output
