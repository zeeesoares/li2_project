#include <rogue.h>


int main(void) {
	srandom(time(NULL));
	keypad(stdscr, true);
	start_color();
	
	//ver engine.c
	ncursesSetUp();

	gameState * game;
	game = malloc(sizeof(struct gameState));

	player * user;
	char ** map;
	position start_pos = {rand() % 17 + 30,rand() % 17 + 20};
	int inputs = 0;

	//ver map.c
	map = mapSetUp();
	drawEverything(map);

	//ver log.c
	logSetUp();

	//setup do "player/user"
	user = playerSetUp(start_pos);

	game->map = map;
	game->user = user;
	// ver engine.c
	gameLoop(inputs,game);

	closeGame(game);
	return 0;
}
