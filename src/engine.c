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


player* jogador;
tile** map;

void drawTile(void)
{ 
  for (int y = 5; y < 50; y++)
  { 
    for (int x = 5; x < 150; x++)
    { 
      mvaddch(y, x, map[y][x].ch);
    } 
  } 
} 

void drawEntity(player* entity)
{ 
  mvaddch(entity->posY, entity->posX, entity->ch);
} 