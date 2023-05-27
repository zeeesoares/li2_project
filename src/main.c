#include <rogue.h>


/*
- a103995 / José Soares

Função main do jogo e iniacialização do mesmo
*/

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
	game->modo.tutorial = 0;

	// loop do menu
	menuLoop(inputs,game);

	// loop principal do jogo
	while (game->modo.jogar) {
		//inicializaçao dos tipos
		game->numTochas = 3;
		game->state = 0;
		player * users;
		entity_mob * mobs;
		tile ** map;
		chest * chest;
		shop * shop;

		//ver map.c
		map = mapSetUp(createMap());

		//setup do "player/user"
		users = playerSetUp(map);

		//setup do "mob"
		mobs = createMobArray(30,map);
		chest = createChestArray(8,map);
		shop = shopSetup(map);

		//inicializaçao do game
		game->map = map;
		game->chest = chest;
		game->mobs = mobs;
		game->user = users;
		game->shop = shop;
		
		//inicializaçao da parte visual
		makeFOV(game, game->user->lanterna);
        isMobVisible(game->shop,game->mobs, game->map, game->chest);
        drawEverything(game);

        // ver engine.c
        gameLoop(inputs,game);
        closeGame(game);
        menuLoop(inputs,game);
	}
	clear();
	endwin();
	return 0;

}


