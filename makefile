CC = gcc
CFLAGS = -lncurses -lm -I./include/ -Wall -Wextra -pedantic -O2
SOURCES = ./src/*.c

all: rogue run clean

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o jogo

run:
	./jogo

clean:
	rm jogo
