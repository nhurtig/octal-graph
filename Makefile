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

main.o: graph.h game_tree.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

graph.o: graph.h graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp

game_tree.o: game_tree.h graph.h game_tree.cpp
	$(CC) $(CFLAGS) -c game_tree.cpp
