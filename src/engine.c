#include <rogue.h>

bool cursesSetup(void){
    initscr();
	noecho();
	curs_set(0);

	if (has_colors()){
		start_color();

		init_pair(VISIBLE_COLOR,COLOR_WHITE,COLOR_BLACK);
		init_pair(SEEN_COLOR,COLOR_BLUE,COLOR_BLACK);
		return true;
	}
	else{
		mvprintw(20,50, "O sistema não suporta cores. Impossível iniciar jogo!");
		getch();
		return false;
	}
}


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
		handleInput(input,game->user);
	}
    return 0;
}

void closeGame(gameState * game)
{
	endwin();
	free(game->user);
	free(game->map);
}