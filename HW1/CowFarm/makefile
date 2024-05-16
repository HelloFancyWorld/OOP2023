all: main

main: Farm.o main.o
	g++ main.o Farm.o -o main
Farm.o: Farm.cpp Farm.h Cow.h
	g++ -c Farm.cpp -o Farm.o
main.o: main.cpp Farm.h Cow.h
	g++ -c main.cpp -o main.o

.PHONY: clean
clean:
	rm -f main.o Farm.o