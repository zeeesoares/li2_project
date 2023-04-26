#include <rogue.h>


// setup das funçoes do ncurses
int ncursesSetUp() {
	initscr();
	curs_set(0);
	printw("Hello World!");
	noecho();
	start_color();
	bkgd(COLOR_BLACK);
	refresh();
    return 0;
}

// loop que faz o jogo acontecer
int gameLoop(int input, gameState * game) {
    while ((input = getch()) != 'q') {
		handleInput(input,game);
		handleInventory(input);
	}
    return 0;
}

void closeGame(gameState * game)
{
	endwin();
	free(game->user);
	free(game->map);
}