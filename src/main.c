#include <rogue.h>


int main(void) {

	// setup da lib nCurses (ver engine.c)
	ncursesSetUp();

	srandom(time(NULL));
	start_color();

	// variavel que guarda todos os inputs do programa
	int inputs = 0;
	
	// inicializaçao da struct game
	gameState * game;
	game = malloc(sizeof(struct gameState));
	game->modo.jogar = 1;
	game->modo.sair = 0;

	// loop do menu
	menuLoop(inputs,game);

	// loop principal do jogo
	while (game->modo.jogar) {
		//inicializaçao dos tipos
		player * user;
		entity_mob * mobs;
		tile ** map;
		chest * chest;
		shop * shop;

		//ver map.c
		map = mapSetUp(createMap());

		//ver log.c
		logSetUp();

		//setup do "player/user"
		user = playerSetUp(map);

		//setup do "mob"
		mobs = createMobArray(12,map);
		chest = createChestArray(8,map);
		shop = shopSetup(map);

		//inicializaçao do game
		game->map = map;
		game->chest = chest;
		game->mobs = mobs;
		game->user = user;
		game->shop = shop;
		

		makeFOV(game);
		isMobVisible(game->shop,game->mobs, game->map, game->chest);
		drawEverything(game);
		// ver engine.cend:
		gameLoop(inputs,game);
		clear();
		closeGame(game);
		menuLoop(inputs,game);
	}
	clear();
	endwin();
	return 0;

}
