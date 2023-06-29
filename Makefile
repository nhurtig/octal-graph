CC = g++

CFLAGS = -Wall -Werror

all: main

run: main
	./main

memcheck: main
	valgrind ./main

clean:
	rm *.o main

main: main.o graph.o
	$(CC) $(CFLAGS) -o main main.o graph.o

main.o: graph.h

graph.o: graph.h
