#include <rogue.h>

player * playerSetUp(position start_pos, tile ** map) {
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    while (map[start_pos.y-5][start_pos.x-5].ch == '#')
        start_pos.x += 2;
    newPlayer->pos = start_pos;
    newPlayer->ch = '@';

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
    if (game->map[y-5][x-5].ch == '.') {
        movePlayer(y, x, game->user);
    }
}