all: clean main.o Matrix.o Gas.o
	g++ -std=c++14 -o a main.o Matrix.o
Gas.o:Gas.cpp
	g++ -c Gas.cpp
determine.o:determine.cpp
	g++ -c determine.cpp
main.o: main.cpp
	g++ -std=c++14 -c main.cpp
Matrix.o:Matrix.h Matrix.cpp
	g++ -std=c++14 -c Matrix.cpp Matrix.h
clean:
	del -f a main.o Matrix.o Gas.o b determine.o