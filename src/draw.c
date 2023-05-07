#include <rogue.h>

// desenha toda a parte gráfica do jogo e é chamada iterativamente na funcao gameLoop(engine.c)
void drawEverything(gameState * game) {
    clear();
    drawMap(game->map);
    drawPlayer(game->user);
    drawInterface();
    verificaShop(game);
    drawInventory();
    drawStatus();
    drawMob(game->mob, game->map);
    drawShop(game->shop, game->map);
    drawCoins(game->user);
    verificaCoins(game);
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
    mvprintw(17,160,"|  (1) Sword - NONE                     |");
    mvprintw(18,160,"|  (2) Bow - NONE                       |");
    mvprintw(19,160,"|  (3) Potion (Poison) - NON            |");
    mvprintw(20,160,"|                                       |");
    mvprintw(21,160,"+---------------------------------------+");
}

// draw da quantidade de moedas do user
void drawCoins(player * user) {
    mvprintw(5,160,"+---------+");
    mvprintw(6,160,"|         |");
    mvprintw(7,160,"|  %.5d  |",user->coins);
    mvprintw(8,160,"|  Coins  |");
    mvprintw(9,160,"|         |");
    mvprintw(10,160,"+---------+");
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
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"|                                       |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");

    
}

void drawShopInterface() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =SHOP LIST=                           |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|  (z) Swords                           |");
    mvprintw(28,160,"|         |______________               |");
    mvprintw(29,160,"|  [======|______________>              |");
    mvprintw(30,160,"|         |                             |");
    mvprintw(31,160,"|                                       |");
    mvprintw(32,160,"|  (x) Bows                             |");
    mvprintw(33,160,"|                                       |");
    mvprintw(34,160,"|      (                                |");
    mvprintw(35,160,"|       )                               |");
    mvprintw(36,160,"|   ##-------->                         |");
    mvprintw(37,160,"|       )                               |");
    mvprintw(38,160,"|      (                                |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|  (c) Potions                          |");
    mvprintw(41,160,"|      :~:                              |");
    mvprintw(42,160,"|      | |                              |");
    mvprintw(43,160,"|     .' `.                             |");
    mvprintw(44,160,"|   .'     `.                           |");
    mvprintw(45,160,"|   |       |                           |");
    mvprintw(46,160,"|    `.._..'                            |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}


void drawShopInterfaceSword() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Swords=                              |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|    __                                 |");
    mvprintw(28,160,"|    ||            /|          N        |");
    mvprintw(29,160,"|   _||_          |||          U        |");
    mvprintw(30,160,"|  ( || )         |||          N        |");
    mvprintw(31,160,"|    ||           |||       ___O___     |");
    mvprintw(32,160,"|    ||           |||         | |       |");
    mvprintw(33,160,"|    ||           |||         | |       |");
    mvprintw(34,160,"|    ||           |||         | |       |");
    mvprintw(35,160,"|    ||           |||         | |       |");
    mvprintw(36,160,"|    ||        ~-[{o}]-~      | |       |");
    mvprintw(37,160,"|    ||           |/|         | |       |");
    mvprintw(38,160,"|    ||           |/|         | |       |");
    mvprintw(39,160,"|    |/           |_|         |/        |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|  Dano: 24    Dano: 30     Dano: 40    |");
    mvprintw(42,160,"|  Rank: B     Rank: A      Rank: S     |");
    mvprintw(43,160,"|  Cost: 4000  Cost: 5000   Cost: 7000  |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"|                         (v) - sair    |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}

void drawShopInterfaceBows() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Bows=                                |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|                                       |");
    mvprintw(28,160,"|                                       |");
    mvprintw(29,160,"|     (                                 |");
    mvprintw(30,160,"|      )                                |");
    mvprintw(31,160,"|      (                                |");
    mvprintw(32,160,"|    ##------>                          |");
    mvprintw(33,160,"|      (                                |");
    mvprintw(34,160,"|      )                                |");
    mvprintw(35,160,"|     (                                 |");
    mvprintw(36,160,"|                                       |");
    mvprintw(37,160,"|  Dano: 20                             |");
    mvprintw(38,160,"|  Rank: A                              |");
    mvprintw(39,160,"|  Cost: 4000                           |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"|                         (v) - sair    |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}

void drawShopInterfacePotions() {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Potions=                             |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|                                       |");
    mvprintw(28,160,"|                                       |");
    mvprintw(29,160,"|      )           |                    |");
    mvprintw(30,160,"|     (           -o-           ||      |");
    mvprintw(31,160,"|   .-`-.        /-`-.        __(l      |");
    mvprintw(32,160,"|   :   :        :   :       :   :      |");
    mvprintw(33,160,"|   :   :        :   :       :   :      |");
    mvprintw(34,160,"|   :___:        :___:       :___:      |");
    mvprintw(35,160,"|                                       |");
    mvprintw(36,160,"|  Flame        Poison       Granade    |");
    mvprintw(37,160,"|  Dano: 20     Dano: 15     Dano: 35   |");
    mvprintw(38,160,"|  Tempo: 1s    Tempo: 2s    Tempo: 1s  |");
    mvprintw(39,160,"|  Cost: 2000   Cost: 4000   Cost: 6000 |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"|                         (v) - sair    |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
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

   :~:    
   | |    
  .' `.   
.'     `. 
|       | 
 `.._..' 

    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =Swords=                              |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|    __                                 |");
    mvprintw(28,160,"|    ||            /|          N        |");
    mvprintw(29,160,"|   _||_          |||          U        |");
    mvprintw(30,160,"|  ( || )         |||          N        |");
    mvprintw(31,160,"|    ||           |||       ___O___     |");
    mvprintw(32,160,"|    ||           |||         | |       |");
    mvprintw(33,160,"|    ||           |||         | |       |");
    mvprintw(34,160,"|    ||           |||         | |       |");
    mvprintw(35,160,"|    ||           |||         | |       |");
    mvprintw(36,160,"|    ||        ~-[{o}]-~      | |       |");
    mvprintw(37,160,"|    ||           |/|         | |       |");
    mvprintw(38,160,"|    ||           |/|         | )       |");
    mvprintw(39,160,"|    |/           |_|         |/        |");
    mvprintw(40,160,"|                                       |");
    mvprintw(41,160,"|  Dano: 24    Dano: 30     Dano: 40    |");
    mvprintw(42,160,"|  Rank: B     Rank: A      Rank: S     |");
    mvprintw(43,160,"|  Cost: 4000  Cost: 5000   Cost: 7000  |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"|                                       |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
  __
  ||
 _||_
( || )
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  \/  

    /|
   |\|
   |||
   |||
   |||
   |||
   |||
   |||
~-[{o}]-~
   |/|
   |/|

   O
   D
   I
___E___
  | |
  | |
  | |
  | |
  | |
  | |
  | |
  \ /
   '

       /\
/vvvvvvv \----------------------------,
`^^^^^^^ /==========================="
       \/


                (
                 \
                  )
             ##-------->        niger
                  )
                 /
                (

    \|/
   - o -
    /-`-.
    :   :
    :TNT:
    :___:
*/