#include <rogue.h>

// desenha toda a parte gráfica do jogo e é chamada iterativamente na funcao gameLoop(engine.c)
void drawEverything(gameState * game) {
    clear();
    drawMap(game->map);
    handleInventory(game);
    drawPlayer(game->user);
    if (game->interface) drawInterfaceMobStatus(game);
    else drawInterface();
    verificaShop(game);
    drawSelected(game->shop);
    drawInventory(game->user);
    drawStatus(game);
    //isMobVisible(game->shop,game->mobs, game->map);
    drawMobs(game->mobs, game->map);
    drawShop(game->shop, game->map);
    drawCoins(game->user);

}

// draw (em processo) do menu inicial
void drawMenu(menu menu) {
    mvprintw(14,65,"oooooooooo.  ooooooooo.     .oooooo.     .oooooo.    ooooo     ooo oooooooooooo");
    mvprintw(15,65,"`888'   `Y8b `888   `Y88.  d8P'  `Y8b   d8P'  `Y8b   `888'     `8' `888'     `8");
    mvprintw(16,65," 888     888  888   .d88' 888      888 888            888       8   888");
    mvprintw(17,65," 888oooo888'  888ooo88P'  888      888 888            888       8   888oooo8");
    mvprintw(18,65," 888    `88b  888`88b.    888      888 888     ooooo  888       8   888    ");
    mvprintw(19,65," 888    .88P  888  `88b.  `88b    d88' `88.    .88'   `88.    .8'   888       o");
    mvprintw(20,65,"o888bood8P'  o888o  o888o  `Y8bood8P'   `Y8bood8P'      `YbodP'    o888ooooood8 ");

    if (menu.jogar == 1) {
        mvprintw(31,65," 888888ba  dP         .d888888  dP    dP          d8     ");
        mvprintw(32,65," 88    `8b 88        d8'    88  Y8.  .8P         d8'      ");
        mvprintw(33,65,"a88aaaa8P' 88        88aaaaa88a  Y8aa8P         d8'       ");
        mvprintw(34,65," 88        88        88     88     88          Y8. 888888888888");
        mvprintw(35,65," 88        88        88     88     88           Y8.        ");
        mvprintw(36,65," dP        88888888P 88     88     dP            Y8       ");

        mvprintw(41,65," 88888888b dP    dP dP d888888P ");
        mvprintw(42,65," 88        Y8.  .8P 88    88");
        mvprintw(43,65,"a88aaaa     Y8aa8P  88    88");
        mvprintw(44,65," 88        d8'  `8b 88    88");
        mvprintw(45,65," 88        d8'  `8b 88    88 ");
        mvprintw(46,65," 88888888P dP    dP dP    dP");                                   
    }
    else {
        mvprintw(31,65," 888888ba  dP         .d888888  dP    dP       ");
        mvprintw(32,65," 88    `8b 88        d8'    88  Y8.  .8P        ");
        mvprintw(33,65,"a88aaaa8P' 88        88aaaaa88a  Y8aa8P         ");
        mvprintw(34,65," 88        88        88     88     88      ");
        mvprintw(35,65," 88        88        88     88     88            ");
        mvprintw(36,65," dP        88888888P 88     88     dP           ");

        mvprintw(41,65," 88888888b dP    dP dP d888888P                  d8     ");
        mvprintw(42,65," 88        Y8.  .8P 88    88                    d8  ");
        mvprintw(43,65,"a88aaaa     Y8aa8P  88    88                  d8'      ");
        mvprintw(44,65," 88        d8'  `8b 88    88                 d8' 8888888888888      ");
        mvprintw(45,65," 88        d8'  `8b 88    88                  Y8.");
        mvprintw(46,65," 88888888P dP    dP dP    dP                   Y8.");   
    }
                                             
}

// draw do map, funcao chamada depois da inicialização e criacao do mapa na drawMap
void drawMap(tile ** map) {
    int rows = 55; 
	int cols = 145;
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
void drawMob(entity_mob mob, tile ** map) {
    int margem = 3;
    if (mob.visible && map[mob.pos.y-margem][mob.pos.x-margem].walkable && mob.vida != 0)
        mvaddch(mob.pos.y,mob.pos.x,mob.ch | COLOR_PAIR(SWORDC));
}

void drawMobs(entity_mob mobs[], tile **map) {
    for (int i = 0; i < 10; i++) { // percorre o array de mobs
        drawMob(mobs[i], map); // desenha o mob atual
    }
}

void drawShop(shop * shop, tile ** map) {
    int margem = 3;
    if (map[shop->pos.y-margem][shop->pos.x-margem].visible == 1)
        mvaddch(shop->pos.y,shop->pos.x,shop->ch | COLOR_PAIR(SWORDC));
}

// draw do Inventory do user
void drawInventory(player * user) {
    mvprintw(14,160,"+---------------------------------------+");
    mvprintw(15,160,"| =Inventory=                           |");
    mvprintw(16,160,"|                                       |");
    if (user->sword.dano > 0)
        mvprintw(17,160,"|  (1) Sword - DG: %d Rank: %c           |", user->sword.dano, user->sword.class);
    else mvprintw(17,160,"|                                       |");
    if (user->bow.dano > 0)
        mvprintw(18,160,"|  (2) Bow - DG: %d Rank: %c             |", user->bow.dano, user->bow.class);
    else mvprintw(18,160,"|                                       |");
    if (user->potion.dano > 0)
        mvprintw(19,160,"|  (3) Potion - DG: %d Rank: %c          |",user->potion.dano, user->potion.class);
    else mvprintw(19,160,"|                                       |");
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
    mvprintw(27,160,"|  (m) MAP STATUS                       |");
    mvprintw(28,160,"|  SHOP LIST                            |");
    mvprintw(29,160,"|                                       |");
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

void drawInterfaceMobStatus(gameState * game) {
    mvprintw(24,160,"+---------------------------------------+");
    mvprintw(25,160,"| =MAP STATUS=                          |");
    mvprintw(26,160,"|                                       |");
    mvprintw(27,160,"|  (1) You                              |");
    if (game->shop->visible == 1)
        mvprintw(28,160,"|  (2) Shop                             |");
    else 
        mvprintw(28,160,"|                                       |");
    mvprintw(29,160,"|                                       |");
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
    mvprintw(47,160,"|                             (n) sair  |");
    mvprintw(48,160,"+---------------------------------------+");
    int j = 0; // variável auxiliar para percorrer a lista de mobs visíveis
    int i = 1;
    int linha = 29;
    while (j < 10) {
        if ((game->mobs+j)->visible) {
            mvprintw(linha,161,"  (%d) %5s",i,(game->mobs+j)->nome);
            linha++;
            i++;
        }
        j++; // atualiza j para o próximo mob
    }
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

void drawSelected(shop * shop) {
    switch (shop->state)
    {
    case 1:
        switch (shop->sword)
        {
        case 1:
            mvaddch(44,166,'O' | COLOR_PAIR(SWORDC));
            break;
        case 2:
            mvaddch(44,179,'O' | COLOR_PAIR(SWORDC));
            break;
        case 3:
            mvaddch(44,191,'O' | COLOR_PAIR(SWORDC));
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (shop->bow)
        {
        case 1:
            mvaddch(44,166,'O' | COLOR_PAIR(SWORDC));
            break;
        case 2:
            mvaddch(44,179,'O' | COLOR_PAIR(SWORDC));
            break;
        case 3:
            mvaddch(44,191,'O' | COLOR_PAIR(SWORDC));
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (shop->potion)
        {
        case 1:
            mvaddch(41,166,'O' | COLOR_PAIR(SWORDC));
            break;
        case 2:
            mvaddch(41,179,'O' | COLOR_PAIR(SWORDC));
            break;
        case 3:
            mvaddch(41,191,'O' | COLOR_PAIR(SWORDC));
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
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
    mvprintw(38,160,"|    |/           |_|         |/        |");
    mvprintw(39,160,"|                                       |");
    mvprintw(40,160,"|  Dano: 24    Dano: 30     Dano: 40    |");
    mvprintw(41,160,"|  Rank: B     Rank: A      Rank: S     |");
    mvprintw(42,160,"|  Cost: 4000  Cost: 5000   Cost: 7000  |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"| (a) <- | (d) -> | (b) buy |  (v) sair |");
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
    mvprintw(46,160,"| (a) <- | (d) -> | (b) buy |  (v) sair |");
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
    mvprintw(40,160,"|  Rank: B      Rank: A      Rank: S    |");
    mvprintw(41,160,"|                                       |");
    mvprintw(42,160,"|                                       |");
    mvprintw(43,160,"|                                       |");
    mvprintw(44,160,"|                                       |");
    mvprintw(45,160,"|                                       |");
    mvprintw(46,160,"| (a) <- | (d) -> | (b) buy |  (v) sair |");
    mvprintw(47,160,"|                                       |");
    mvprintw(48,160,"+---------------------------------------+");
}

// draw do Status
void drawStatus(gameState * game) {
    mvprintw(5,179, "+--------------------+");
    mvprintw(6,179, "|                    |");
    mvprintw(7,179, "|  HP: %3d/100       |", game->user->vida);
    mvprintw(8,179, "|  Stamina: %3d/100  |", game->user->stamina);
    mvprintw(9,179, "|  Mobs: x/10        |");
    mvprintw(10,179,"|                    |");
    mvprintw(11,179,"+--------------------+");
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
