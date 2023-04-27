#include <rogue.h>


int main(void) {
	srandom(time(NULL));
	start_color();
	
	//ver engine.c
	ncursesSetUp();

	gameState * game;
	game = malloc(sizeof(struct gameState));
	game->modo.jogar = 1;
	game->modo.sair = 0;

	player * user;
	entity_mob * mob;
	char ** map;
	position start_pos = {rand() % 17 + 30,rand() % 17 + 20};
	position start_posMOb = {rand() % 17 + 20,rand() % 17 + 20};
	int inputs = 0;

	menuLoop(inputs,game);
	//ver map.c
	map = mapSetUp();
	//ver log.c
	logSetUp();

	//setup do "player/user"
	user = playerSetUp(start_pos);

	//setup do "mob"
	mob = mobsSetUp(start_posMOb);

	//inicializaçao do game
	game->map = map;
	game->user = user;
	game->mob = mob;


	drawEverything(game);
	// ver engine.cend:
	gameLoop(inputs,game);

	closeGame(game);
	return 0;
}
