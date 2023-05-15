#include <rogue.h>


// setup das funçoes do ncurses
int ncursesSetUp() {
	initscr();
	curs_set(0);
	printw("Hello World!");
	cbreak();
	noecho();
	start_color();	
	init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
	init_pair(TRANSPARENT_COLOR, COLOR_BLACK, COLOR_BLACK);
	init_pair(SWORDC,COLOR_RED,COLOR_BLACK);
	init_pair(BOWC,COLOR_GREEN,COLOR_BLACK);
	init_pair(POTIONC,COLOR_YELLOW,COLOR_BLACK);
	init_pair(MOBCOLOR,COLOR_CYAN,COLOR_BLACK);
	bkgd(COLOR_BLACK);
	refresh();
    return 0;
}


// loop principal que faz o jogo acontecer 
int gameLoop(int input, gameState * game) {
    while ((input = getch()) != 'q') {  // get do char atraves do teclado e o passa as funcoes
		handleInput(input,game);  // responsavel por mover o player e as suas interaçoes
		drawEverything(game);  // draw iterativo que "atualiza" o jogo
	}
  return 0;
}


int menuLoop(int input, gameState * game) {
	keypad(stdscr, true);
	drawMenu();
	while ((input = getch()) != 'q') {
		if (game->modo.jogar == 1 && input == 10) {
			game->modo.jogar = 0;
			game->modo.sair = 1;
			break;
		}
		else if (game->modo.jogar == 1 && input == 10) {
			game->modo.jogar = 1;
			game->modo.sair = 0;
			break;
		}
	}
	return 0;
}


void closeGame(gameState * game)  // funcao que encerra o ncurses e liberta a memoria da heap
{
	free(game->user);
	freeMobList(game->mobs);
	free(game->shop);
	freeMap(game->map);
	endwin();
}