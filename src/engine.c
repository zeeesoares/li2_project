#include <rogue.h>


// setup das funçoes do ncurses
int ncursesSetUp() {
	initscr();
	curs_set(0);
	printw("Hello World!");
	noecho();
	start_color();	
	init_pair(VISIBLE_COLOR, COLOR_BLUE, COLOR_BLACK);
	init_pair(WALK_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(SWORDC,COLOR_RED,COLOR_BLACK);
	init_pair(BOWC,COLOR_GREEN,COLOR_BLACK);
	init_pair(POTIONC,COLOR_YELLOW,COLOR_BLACK);
	bkgd(COLOR_BLACK);
	refresh();
    return 0;
}


// loop que faz o jogo acontecer
int gameLoop(int input, gameState * game) {
	if (game->modo.sair == 1) return 0;
    while ((input = getch()) != 'q') {
		handleInput(input,game);
		drawEverything(game);
		//handleInventory(input,game);
	}
    return 0;
}

int menuLoop(int input, gameState * game) {
	keypad(stdscr, true);
	drawMenu();
	while ((input = getch()) != 'k') {
		if (game->modo.jogar == 1 && input == KEY_DOWN) {
			game->modo.jogar = 0;
			game->modo.sair = 1;
			break;
		}
		else if (game->modo.jogar == 1 && input == KEY_UP) {
			game->modo.jogar = 1;
			game->modo.sair = 0;
			break;
		}
	}
	return 0;
}

void closeGame(gameState * game)
{
	free(game->user);
	freeMap(game->map);
	endwin();
}