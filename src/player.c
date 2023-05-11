#include <rogue.h>

player * playerSetUp(tile ** map) {
    position start_pos = {rand() % 87 + 30,rand() % 17 + 20};
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    newPlayer->pos = start_pos;
    newPlayer->ch = '@';
    newPlayer->color = COLOR_PAIR(SWORDC);
    newPlayer->coins = 0;
    newPlayer->sword.act = 1;
    newPlayer->sword.dano = 10;
    newPlayer->bow.act = 0;
    newPlayer->bow.dano = 0;
    newPlayer->potion.act = 0;
    newPlayer->potion.dano = 0;
    return newPlayer;
}




/*
void handleInventory(gameState * game) {
    keypad(stdscr, true);
    switch (input)
    {
    case '1':
        game->user->weapon = 1;
        break;
    case '2':
        game->user->weapon = 2;
        break;
    case '3':
        game->user->weapon = 3;
        break;
    case '4':
        game->user->weapon = 4;
        break;
    default:
        break;
    }
}
*/
void handleInput(int input, gameState * game) {
    keypad(stdscr, true);
    switch (input)
    {
    case KEY_UP:
        checkMove(game->user->pos.y - 1,game->user->pos.x, game);
        break;
    case KEY_DOWN:
        checkMove(game->user->pos.y + 1,game->user->pos.x, game);
        break;
    case KEY_LEFT:
        checkMove(game->user->pos.y,game->user->pos.x - 1, game);
        break;
    case KEY_RIGHT:
        checkMove(game->user->pos.y,game->user->pos.x + 1, game);
        break;
    case '1':
        if (game->user->sword.act == 1)
            game->user->weapon = 0;
        break;
    case '2':
        if (game->user->bow.act == 1)    
            game->user->weapon = 1;
        break;
    case '3':
        if (game->user->potion.act == 1)  
            game->user->weapon = 2;
        break;
    case 'z':
        if (game->shop->act == 1 && game->shop->state == 0)
            game->shop->state = 1;
        break;
    case 'x':
        if (game->shop->act == 1  && game->shop->state == 0)
            game->shop->state = 2;
        break;
    case 'c':
        if (game->shop->act == 1  && game->shop->state == 0)
            game->shop->state = 3;
        break;
    case 'a':
        if (game->shop->act == 1) {
            selectItem(game->shop,1);
        }
        break;
    case 'd':
        if (game->shop->act == 1) {
            selectItem(game->shop,2);
        }
        break;
    case 'v':
        game->shop->state = 0;
        break;
    case 'i':
        //projetil('i',game);
        //create_thread(game);
        break;
    case 'j':
        //projetil('j',game);
        
        
        break;
    case 'l':
        //projetil('l',game);

        break;
    case 'k':
        
        //projetil('k',game);

        break;
    default:
        break;
    }
}

void movePlayer(int y, int x, player * user) {

    user -> pos.x = x;
    user -> pos.y = y;

    mvaddch(user->pos.y,user->pos.x,user->ch);

    move(user -> pos.y, user -> pos.x);
}

void checkMove(int y, int x, gameState * game) {
    int margem = 3;
    if (game->map[y-margem][x-margem].ch == '.') {
        clearFOV(game);
        movePlayer(y, x, game->user);
        makeFOV(game);
    }
}