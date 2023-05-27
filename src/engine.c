#include <rogue.h>

/*
- a103995 / José Soares

Funções relacionadas à engine/ setup de jogo
*/


// setup das funçoes do ncurses
int ncursesSetUp() {
	initscr();
	curs_set(0);
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

/*
- a103995 / José Soares

Funções relacionadas à engine/ setup de jogo
*/

// loop principal que faz o jogo acontecer 
int gameLoop(int input, gameState * game) {
	//startMonsterThreads(game);
	cbreak();
    while ((input = getch()) != 'q') {  // get do char atraves do teclado e o passa as funcoes
		timeout(1200);
		if (checkPlayer(game->user) == 0) break;
		handleInput(input,game);  // responsavel por mover o player e as suas interaçoes
		healPlayer(game->user);
		checkDano(game->mobs, game->user);
		moveMobs(game->mobs,game->map,game->user);
		isMobVisible(game->shop,game->mobs, game->map, game->chest);
		drawEverything(game);  // draw iterativo que "atualiza" o jogo
        if (contaMobs(game->mobs) == 0) {
            game->state = 1;
            break;
        }
	}
    if (game->state == 1) drawVictory();
    else drawDeath(game->modo);
    while ((input = getch()) != 10) {}
  return 0;
}

/*
- a104526 / Olavo Carreira

Função relacionada à parte do menu inicial
*/
int menuLoop(int input, gameState *game) {
    keypad(stdscr, true);
    drawMenu(game->modo);
    bool tutorialCompleted = false;

    while ((input = getch()) != 10) {
        if (game->modo.jogar == 1 && game->modo.sair == 0 && game->modo.tutorial == 0 && input == KEY_DOWN) {
            game->modo.jogar = 0;
            game->modo.sair = 1;
            game->modo.tutorial = 0;
            clear();
            drawMenu(game->modo);
        }
        else if (game->modo.jogar == 0 && game->modo.sair == 1 && game->modo.tutorial == 0 && input == KEY_UP) {
            game->modo.jogar = 1;
            game->modo.sair = 0;
            game->modo.tutorial = 0;
            clear();
            drawMenu(game->modo);
        }
        else if (game->modo.jogar == 0 && game->modo.sair == 1 && game->modo.tutorial == 0 && input == KEY_DOWN) {
            game->modo.jogar = 0;
            game->modo.sair = 0;
            game->modo.tutorial = 1;
            clear();
            drawMenu(game->modo);
        } 
        else if (game->modo.jogar == 0 && game->modo.sair == 0 && game->modo.tutorial == 1 && input == KEY_UP) {
            game->modo.jogar = 0;
            game->modo.sair = 1;
            game->modo.tutorial = 0;
            clear();
            drawMenu(game->modo);
        }
    }
    
    if (game->modo.tutorial == 1) {
        clear();
        drawTutorial(game->modo);
        
        while ((input = getch()) != 10) {
        }
        
        tutorialCompleted = true;
    }
    
    if (tutorialCompleted) {
        clear();
        game->modo.jogar = 0;
        game->modo.sair = 0;
        game->modo.tutorial = 1;
        menuLoop(input,game);
    }
    
    return 0;
}



/*
- a103995 / José Soares

Funções relacionadas ao fecho de jogo
*/

void closeGame(gameState * game)  // funcao que encerra o ncurses e liberta a memoria da heap
{
	free(game->user);
	free(game->shop);
	free(game->chest);
	free(game->mobs);
	freeMap(game->map);
	endwin();
}