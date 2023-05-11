#include <rogue.h>


int main(void) {
	srandom(time(NULL));
	start_color();

	
	//ver engine.c
	ncursesSetUp();

	gameState * game;
	game = malloc(sizeof(struct gameState));
	game->modo = 0;

	position pos_dungeon;
	player * user;
	tile ** dungeon;
	entity_mob * mobs;
	tile ** map;
	shop * shop;
	int inputs = 0;
	int sair = 0;

	//ver map.c
	map = mapSetUp(createMap());
	dungeon = createDungeonTiles();
	pos_dungeon = setupMapDungeons(dungeon);

	//ver log.c
	logSetUp();

	//setup do "player/user"
	user = playerSetUp(map);

	//setup do "mob"
	mobs = createMobArray(10,map);
	shop = shopSetup(map);
	//inicializaçao do game
	game->map = map;
	game->dungeon = dungeon;
	game->mobs = mobs;
	game->user = user;
	game->shop = shop;
	
	makeFOV(game);
	drawEverything(game);
	// ver engine.cend:
	while (!sair) {
		gameLoop(inputs,game);
		sair = 1;
	}
	closeGame(game);
	return 0;
}
