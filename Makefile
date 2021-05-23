CC=clang
CFLAGS=-Wall -Wextra -ggdb3 -I./inc

all: folders executable

folders:
	mkdir -p bin obj
	
obj/life.o: src/life.c inc/life.h
	${CC} ${CFLAGS} -c src/life.c -o obj/life.o

obj/main.o: src/main.c
	${CC} ${CFLAGS} -c src/main.c -o obj/main.o

executable: obj/main.o obj/life.o
	${CC} ${CFLAGS} -o bin/game_of_life obj/life.o obj/main.o

watch:
	watch ./bin/game_of_life 10 test.txt

clean:
	rm -r obj/ bin/

