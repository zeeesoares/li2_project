#include <rogue.h>

player * playerSetUp(position start_pos) {
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    newPlayer->posX =  start_pos.x;
    newPlayer->posY = start_pos.y;
    newPlayer->ch = '@';

    mvaddch(newPlayer->posY,newPlayer->posX,newPlayer->ch);
    mvprintw(46,122,"rows: %d, cols: %d",newPlayer->posY,newPlayer->posX);
    return newPlayer;
}

void handleInput(int input, player * user) {
    switch (input)
    {
    case 'w':
        checkMove(user->posY - 1,user->posX, user);
        break;
    case 's':
        checkMove(user->posY + 1,user->posX, user);
        break;
    case 'a':
        checkMove(user->posY,user->posX - 1, user);
        break;
    case 'd':
        checkMove(user->posY,user->posX + 1, user);
        break;
    default:
        break;
    }
    mvprintw(46,122,"rows: %d, cols: %d",user->posY,user->posX);
}

void movePlayer(int y, int x, player * user) {
    mvaddch(user->posY,user->posX,'.');

    user -> posX = x;
    user -> posY = y;

    mvaddch(user->posY,user->posX,user->ch);
    move(user -> posY, user -> posX);
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