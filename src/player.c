#include <rogue.h>

player * playerSetUp(position start_pos) {
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    newPlayer->posX =  start_pos.x;
    newPlayer->posY = start_pos.y;
    newPlayer->ch = '@';

    start_color();

	init_pair(COLOR_BLUE,COLOR_BLUE,COLOR_BLACK);
	init_pair(COLOR_GREEN,COLOR_GREEN,COLOR_BLACK);
	init_pair(COLOR_RED,COLOR_RED,COLOR_BLACK);
    

    attron(COLOR_PAIR(COLOR_BLUE));
    mvaddch(newPlayer->posY,newPlayer->posX,'@');
    attroff(COLOR_PAIR(COLOR_BLUE));
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
    start_color();

	init_pair(COLOR_BLUE,COLOR_BLUE,COLOR_BLACK);
	init_pair(COLOR_GREEN,COLOR_GREEN,COLOR_BLACK);
	init_pair(COLOR_RED,COLOR_RED,COLOR_BLACK);
    



    mvaddch(user->posY,user->posX,'.');

    user -> posX = x;
    user -> posY = y;
    attron(COLOR_PAIR(COLOR_BLUE));
    mvaddch(user->posY,user->posX,'@');
    attroff(COLOR_PAIR(COLOR_BLUE));
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