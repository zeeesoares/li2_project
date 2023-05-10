#include <rogue.h>

player * playerSetUp(position start_pos) {
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    newPlayer->pos = start_pos;
    newPlayer->ch = '@';
    newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);

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
    clearFOV(user);
    user -> pos.x = x;
    user -> pos.y = y;
    makeFOV(user);

    init_pair(1, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1)); // Ativa a cor vermelha
    mvaddch(user->pos.y,user->pos.x,user->ch);
    attroff(COLOR_PAIR(1)); // Desativa a cor vermelha
    move(user -> pos.y, user -> pos.x);
}

void checkMove(int y, int x, gameState * game) {
    if (game->map[y-5][x-5] == '.') {
        imprimeEspaco(game->user->pos.y,game->user->pos.x);
        movePlayer(y, x, game->user);
    }
}