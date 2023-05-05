#include <rogue.h>

// desenha toda a parte gráfica do jogo e é chamada iterativamente na funcao gameLoop(engine.c)
void drawEverything(gameState * game) {
    clear();
    drawMap(game->map);
    drawPlayer(game->user); 
    drawCoins();
    drawInterface();
    verificaShop(game);
    drawInventory();
    drawStatus();
    drawMob(game->mob, game->map);
    drawShop(game->shop, game->map);
}

// draw (em processo) do menu inicial
void drawMenu() {
    mvprintw(24,50,"oooooooooo.  ooooooooo.     .oooooo.     .oooooo.    ooooo     ooo oooooooooooo");
    mvprintw(25,50,"`888'   `Y8b `888   `Y88.  d8P'  `Y8b   d8P'  `Y8b   `888'     `8' `888'     `8");
    mvprintw(26,50," 888     888  888   .d88' 888      888 888            888       8   888");
    mvprintw(27,50," 888oooo888'  888ooo88P'  888      888 888            888       8   888oooo8");
    mvprintw(28,50," 888    `88b  888`88b.    888      888 888     ooooo  888       8   888    ");
    mvprintw(29,50," 888    .88P  888  `88b.  `88b    d88' `88.    .88'   `88.    .8'   888       o");
    mvprintw(30,50,"o888bood8P'  o888o  o888o  `Y8bood8P'   `Y8bood8P'      `YbodP'    o888ooooood8 ");


    mvprintw(41,90,"       dP                                           d8");
    mvprintw(42,90,"       88                                          d8'");
    mvprintw(43,90,"       88 .d8888b. .d8888b. .d8888b. 88d888b.     d8'");
    mvprintw(44,90,"       88 88'  `88 88'  `88 88'  `88 88'  `88     Y8.  88888888");
    mvprintw(45,90,"88.  .d8P 88.  .88 88.  .88 88.  .88 88            Y8.");
    mvprintw(46,90," `Y8888'  `88888P' `8888P88 `88888P8 dP             Y8   ");
    mvprintw(47,90,"                        .88");
    mvprintw(48,90,"                    d8888P");

}

// draw do map, funcao chamada depois da inicialização e criacao do mapa na drawMap
void drawMap(tile ** map) {
    int rows = 55; 
	int cols = 150;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (map[y][x].visible)
			{   //se o espaço for visivel, a funcao drawMap desenha o char da cor VISIBLE
				mvaddch(y+3, x+3, map[y][x].ch | COLOR_PAIR(VISIBLE_COLOR) | A_BOLD);
			}
            if (map[y][x].seen)
            {   //se o espaço ja nao for visivel, a funcao drawMap desenha o char da cor SEEN
				mvaddch(y+3, x+3, map[y][x].ch | COLOR_PAIR(SEEN_COLOR));
			}
            if (map[y][x].transparent)
            {   //se o espaço ja nao for visivel, a funcao drawMap desenha o char da cor SEEN
				mvaddch(y+3, x+3, map[y][x].ch | COLOR_PAIR(TRANSPARENT_COLOR));
			}
		}
	}
}

// draw do player na sua posição atual
void drawPlayer(player * user) {
    mvaddch(user->pos.y, user->pos.x, user->ch | user->color);
}

// draw do mob (experimental)
void drawMob(entity_mob * mob, tile ** map) {
    int margem = 3;
    if (map[mob->pos.y-margem][mob->pos.x-margem].visible == 1)
        mvaddch(mob->pos.y,mob->pos.x,mob->ch | COLOR_PAIR(SWORDC));
}

void drawShop(shop * shop, tile ** map) {
    int margem = 3;
    if (map[shop->pos.y-margem][shop->pos.x-margem].visible == 1)
        mvaddch(shop->pos.y,shop->pos.x,shop->ch | COLOR_PAIR(SWORDC));
}

// draw do Inventory do user
void drawInventory() {
    mvprintw(14,160,"+---------------------------------------+");
    mvprintw(15,160,"| =Inventory=                           |");
    mvprintw(16,160,"|                                       |");
    mvprintw(17,160,"|  (1) Sword - /                        |");
    mvprintw(18,160,"|  (2) Bow - |>                         |");
    mvprintw(19,160,"|  (3) Potion (Poison) - o              |");
    mvprintw(20,160,"|                                       |");
    mvprintw(21,160,"+---------------------------------------+");
}

// draw da quantidade de moedas do user
void drawCoins() {
    mvprintw(5,160,"+---------+");
    mvprintw(6,160,"|         |");
    mvprintw(7,160,"|  Coins  |");
    mvprintw(8,160,"|         |");
    mvprintw(9,160,"+---------+");
}

// draw da interface
void drawInterface() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =MENU INTERFACE=                      |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|  (1) MOB STATUS                       |");
    mvprintw(28,160,"|  (2) SHOP LIST                        |");
    mvprintw(29,160,"|  (ESC)                                |");
    mvprintw(30,160,"|                                       |");
    mvprintw(31,160,"|                                       |");
    mvprintw(32,160,"|                                       |");
    mvprintw(33,160,"|                                       |");
    mvprintw(34,160,"|                                       |");
    mvprintw(35,160,"|                                       |");
    mvprintw(36,160,"|                                       |");
    mvprintw(37,160,"|                                       |");
    mvprintw(38,160,"|                                       |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"+---------------------------------------+");
}

void drawShopInterface() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =SHOP LIST=                           |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|  (1) Sword                            |");
    mvprintw(28,160,"|         |______________               |");
    mvprintw(29,160,"|  [======|______________>              |");
    mvprintw(30,160,"|         |                             |");
    mvprintw(31,160,"|                                       |");
    mvprintw(32,160,"|  (2) Bow                              |");
    mvprintw(34,160,"|      (                                |");
    mvprintw(35,160,"|       )                               |");
    mvprintw(36,160,"|   ##-------->                         |");
    mvprintw(37,160,"|       )                               |");
    mvprintw(38,160,"|      (                                |");
    mvprintw(33,160,"|                                       |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"+---------------------------------------+");
}

// draw do Status
void drawStatus() {
    mvprintw(5,180, "+-------------------+");
    mvprintw(6,180, "|                   |");
    mvprintw(7,180, "|    HP: 100/100    |");
    mvprintw(8,180, "|    Mana: 82/82    |");
    mvprintw(9,180, "|    XP: 11234      |");
    mvprintw(10,180,"|    LVL: 123       |");
    mvprintw(11,180,"|                   |");
    mvprintw(12,180,"+-------------------+");
}

/*
       |______________
[======|______________>
       |
       '
   (
    \
     )
##--------> 
     )
    /
   (
*/