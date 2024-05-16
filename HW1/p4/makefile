all: main

main: chef.o manager.o main.o
	g++ chef.o manager.o main.o -o main
main.o: main.cpp chef.h manager.h
	g++ -c main.cpp -o main.o
chef.o: chef.cpp chef.h
	g++ -c chef.cpp -o chef.o
manager.o: manager.cpp manager.h chef.h
	g++ -c manager.cpp -o manager.o