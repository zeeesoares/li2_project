#include <rogue.h>

void drawEverything(gameState * game) {
    clear();
    drawMap(game->map);
    drawPlayer(game->user); 
    drawCoins();
    drawInterface();
    drawInventory();
    drawStatus();
    drawMob(game->mob);
}

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


void drawMap(tile ** map)
{
    int rows = 40;
	int cols = 135;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (map[y][x].visible)
			{
				mvaddch(y, x, map[y][x].ch | map[y][x].color);
			}
            if (map[y][x].seen)
            {
				mvaddch(y, x, map[y][x].ch | map[y][x].color);
			}
            else
            {
                mvaddch(y,x,' ');
            }
		}
	}
}

void drawPlayer(player * user) {
    mvaddch(user->pos.y, user->pos.x, user->ch | user->color);
}

void drawMob(entity_mob * mob) {
    mvaddch(mob->pos.y,mob->pos.x,mob->ch);
}

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

void drawCoins() {
    mvprintw(5,160,"+---------+");
    mvprintw(6,160,"|         |");
    mvprintw(7,160,"|  Coins  |");
    mvprintw(8,160,"|         |");
    mvprintw(9,160,"+---------+");
}

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