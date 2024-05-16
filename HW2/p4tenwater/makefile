all: main
main: Object.o Splash.o main.o
	g++ Object.o Splash.o main.o -o main
Object.o: Object.h Object.cpp Splash.h
	g++ -c Object.cpp -o Object.o
Splash.o: Splash.cpp Splash.h
	g++ -c Splash.cpp -o Splash.o
main.o: main.cpp Splash.h Object.h
	g++ -c main.cpp -o main.o

.PHONY: clean
clean:
	del main.o Splash.o Object.o