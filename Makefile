CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: main.o main

main: main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm $(wildcard *.o) main
