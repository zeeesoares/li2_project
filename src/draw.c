#include <rogue.h>

void drawEverything(gameState * game) {
    start_color();
    mvprintw(5,180, "+-------------------+");
    mvprintw(6,180, "|                   |");
char vida[12];
    //vida[0]='|';
    for(int i=1;i<((100)-50)/10;i++){
        vida[i]='#';
    }
    
    for(int i=((100)-50)/10;i<11;i++){
        vida[i]='.';
    }
    vida[11]='|';

    mvprintw(7,180, "|   HP:");
    for(int i=1;i<12;i++){
        if((100)-50<50){
            init_pair(2,COLOR_YELLOW,COLOR_BLACK);
            attron(COLOR_PAIR(2));
            mvprintw(7,188+i,"%c",vida[i]);
            attroff(COLOR_PAIR(2));
        }
        if((100)-50<10){
            init_pair(1,COLOR_RED,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(7,188+i,"%c",vida[i]);
            attroff(COLOR_PAIR(1));
        }
        else{
            init_pair(3,COLOR_GREEN,COLOR_BLACK);
            attron(COLOR_PAIR(3));
            mvprintw(7,188+i,"%c",vida[i]);
            attroff(COLOR_PAIR(3));
        } 
    }
        mvprintw(7,200, "|");

        char mana[12];
    //mana[0]='|';
    for(int i=1;i<((100)-20)/10;i++){
        mana[i]='#';
    }
    for(int i=((100)-20)/10;i<11;i++){
        mana[i]='.';
    }

    mana[11]='|';

    mvprintw(8,179, " |   Mana:");
    for(int i=1;i<12;i++){
        if((100)-20<50){
            init_pair(1,COLOR_CYAN,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(8,188+i,"%c",mana[i]);
            attroff(COLOR_PAIR(1));
        }
        else{
            init_pair(1,COLOR_BLUE,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(8,188+i,"%c",mana[i]);
            attroff(COLOR_PAIR(1));
        }    
    }
    mvprintw(8,200, "|");

    mvprintw(9,180, "|   XP: 11234       |");
    mvprintw(10,180,"|   LVL: 123        |");
    mvprintw(11,180,"|                   |");
    mvprintw(12,180,"+-------------------+");
    drawMap(game->map);    
    drawCoins();
    drawInterface();
    drawInventory();
    //drawStatus();
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

void drawWeapon(gameState * game) {
    switch (game->user->weapon)
    {
    case 1:
        break;
    case 2:
        if (game->map[game->user->pos.y-5][game->user->pos.x+1-5] == '.')
        mvaddch(game->user->pos.y,game->user->pos.x+1,'/');
        break;
    case 3:
        if (game->map[game->user->pos.y-5][game->user->pos.x+1-5] == '.')
        mvaddch(game->user->pos.y,game->user->pos.x+1,'>');
        break;
    case 4:
        if (game->map[game->user->pos.y-5][game->user->pos.x+1-5] == '.')
        mvaddch(game->user->pos.y,game->user->pos.x+1,'o');
        break;
    default:
        break;
    }
}

void undrawWeapon(int y, int x) {
    imprimeEspaco(y,x);
}