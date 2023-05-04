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

    mvprintw(46,122,"rows: %d, cols: %d",newPlayer->pos.y,newPlayer->pos.x);
    return newPlayer;
}

void handleInput(int input, gameState * game) {
    switch (input)
    {
    case 'w':
        checkMove(game->user->pos.y - 1,game->user->pos.x, game);
        break;
    case 's':
        checkMove(game->user->pos.y + 1,game->user->pos.x, game);
        break;
    case 'a':
        checkMove(game->user->pos.y,game->user->pos.x - 1, game);
        break;
    case 'd':
        checkMove(game->user->pos.y,game->user->pos.x + 1, game);
        break;
    case 49:
        game->user->color = COLOR_PAIR(SWORDC);
        break;
    case 50:
        game->user->color = COLOR_PAIR(BOWC);
        break;
    case 51:
        game->user->color = COLOR_PAIR(POTIONC);
        break;
    default:
        break;
    }
    mvprintw(46,122,"rows: %d, cols: %d",game->user->pos.y,game->user->pos.x);
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