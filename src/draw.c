#include <rogue.h>

void drawEverything(gameState * game) {
    drawMap(game->map);    
    drawCoins();
    drawInterface();
    drawInventory();
    drawStatus();
    drawMob(game->mob);
}

void drawMap(char ** map) {
    int rows = 40;
    int cols = 135;

    // imprimir o mapa
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            mvprintw(i+5, j+5, "%c", map[i][j]);
        }
    }
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