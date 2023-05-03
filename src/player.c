#include <rogue.h>

player * playerSetUp(position start_pos) {
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    newPlayer->pos = start_pos;
    newPlayer->ch = '@';
    newPlayer->weapon=1;

    mvaddch(newPlayer->pos.y,newPlayer->pos.x,newPlayer->ch);
    mvprintw(46,122,"rows: %d, cols: %d",newPlayer->pos.y,newPlayer->pos.x);
    return newPlayer;
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


void handleInventory(int input, gameState * game) {
    keypad(stdscr, true);
    switch (input)
    {
    case '1':
        game->user->weapon = 1;
        drawWeapon(game);
        break;
    case '2':
        game->user->weapon = 2;
        drawWeapon(game);
        break;
    case '3':
        game->user->weapon = 3;
        drawWeapon(game);
        break;
    case '4':
        game->user->weapon = 4;
        drawWeapon(game);
        break;
    default:
        break;
    }
}
void handleInput(int input, gameState * game) {
    switch (input)
    {
    case 'w':
        checkMove(game->user->pos.y - 1,game->user->pos.x, game);
        drawWeapon(game);
        undrawWeapon(game->user->pos.y+1,game->user->pos.x+1);
        break;
    case 's':
        checkMove(game->user->pos.y + 1,game->user->pos.x, game);
        drawWeapon(game);
        undrawWeapon(game->user->pos.y-1,game->user->pos.x+1);
        break;
    case 'a':
        checkMove(game->user->pos.y,game->user->pos.x - 1, game);
        drawWeapon(game);
        undrawWeapon(game->user->pos.y,game->user->pos.x+2);
        break;
    case 'd':
        checkMove(game->user->pos.y,game->user->pos.x + 1, game);
        drawWeapon(game);
        undrawWeapon(game->user->pos.y,game->user->pos.x-1);
        break;
    case '1':
        game->user->weapon = 1;
        break;
    case '2':
        game->user->weapon = 2;
        drawWeapon(game);
        break;
    case '3':
        game->user->weapon = 3;
        drawWeapon(game);
        break;
    case '4':
        game->user->weapon = 4;
        drawWeapon(game);
        break;
    default:
        break;
    }
    mvprintw(46,122,"rows: %d, cols: %d",game->user->pos.y,game->user->pos.x);
}

void movePlayer(int y, int x, player * user) {
    mvaddch(user->pos.y,user->pos.x,'.');

    user -> pos.x = x;
    user -> pos.y = y;

    mvaddch(user->pos.y,user->pos.x,user->ch);
    move(user -> pos.y, user -> pos.x);
}


void checkMove(int y, int x, player * user) {
    switch (mvinch(y,x))
    {
    case '.':
        movePlayer(y,x,user);
        break;
    default:
        break;
    }
}