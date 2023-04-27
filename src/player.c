#include <rogue.h>

player * playerSetUp(position start_pos) {
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    newPlayer->pos = start_pos;
    newPlayer->ch = '@';

    mvaddch(newPlayer->pos.y,newPlayer->pos.x,newPlayer->ch);
    mvprintw(46,122,"rows: %d, cols: %d",newPlayer->pos.y,newPlayer->pos.x);
    return newPlayer;
}

void handleInput(int input, gameState * game) {
    switch (input)
    {
    case KEY_UP:
        checkMove(game->user->pos.y - 1,game->user->pos.x, game->user);
        
        break;
    case KEY_DOWN:
        checkMove(game->user->pos.y + 1,game->user->pos.x, game->user);
        break;
    case KEY_LEFT:
        checkMove(game->user->pos.y,game->user->pos.x - 1, game->user);
        break;
    case KEY_RIGHT:
        checkMove(game->user->pos.y,game->user->pos.x + 1, game->user);
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