CC = g++

CFLAGS = -Wall -Werror -Ofast

all: main

run: main
	./main

memcheck: main
	valgrind ./main

clean:
	rm *.o main

main: main.o graph.o game_tree.o
	$(CC) $(CFLAGS) -o main main.o graph.o game_tree.o

main.o: graph.h game_tree.h

graph.o: graph.h

game_tree.o: game_tree.h graph.h
