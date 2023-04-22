#include <rogue.h>


// setup das funçoes do ncurses
int ncursesSetUp() {
	initscr();
	curs_set(0);
	printw("Hello World!");
	noecho();
	refresh();
    return 0;
}

// loop que faz o jogo acontecer
int gameLoop(int input, player * user) {
    while ((input = getch()) != 'q') {
		handleInput(input,user);
	}
    return 0;
}