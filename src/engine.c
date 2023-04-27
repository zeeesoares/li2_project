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
	if (game->modo.sair == 1) return 0;
    while ((input = getch()) != 'q') {
		handleInput(input,game);
		//handleInventory(input,game);
	}
    return 0;
}

int menuLoop(int input, gameState * game) {
	keypad(stdscr, true);
	drawMenu();
	while ((input = getch()) != 'q') {
		if (game->modo.jogar == 1 && input == 10)
			break;
	}
	return 0;
}

void closeGame(gameState * game)
{
	free(game->user);
	free(game->map);
	endwin();
	reset_shell_mode();
}