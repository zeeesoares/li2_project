#include <rogue.h>

player * playerSetUp(tile ** map) {
    position start_pos = {rand() % 40 + 70,rand() % 17 + 20};
    player * newPlayer;
    newPlayer = malloc(sizeof(player));

    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    newPlayer->pos = start_pos;
    newPlayer->vida = 500;
    newPlayer->stamina = 300;
    newPlayer->ch = '@';
    newPlayer->color = COLOR_PAIR(SWORDC);
    newPlayer->coins = 0;
    newPlayer->weapon = 0;
    newPlayer->sword.class = 'C';
    newPlayer->sword.dano = 10;
    for (int i = 0; i < 3; i++) newPlayer->sword.get[i] = 0;
    newPlayer->bow.class = 'C';
    newPlayer->bow.dano = 0;
    for (int i = 0; i < 3; i++) newPlayer->bow.get[i] = 0;
    newPlayer->potion.class = 'C';
    newPlayer->potion.dano = 0;
    for (int i = 0; i < 3; i++) newPlayer->potion.get[i] = 0;
    return newPlayer;
}

int checkPlayer(player * user) {
    if (user->vida > 0) return 1;
    else return 0;
}

void handleInput(int input, gameState * game) {
    keypad(stdscr, true);
    switch (input)
    {
    case KEY_UP:
        if (game->user->stamina > 20) {
            checkMove(game->user->pos.y - 1,game->user->pos.x, game);
            game->user->stamina-= 3;
        }
        break;
    case KEY_DOWN:
        if (game->user->stamina > 20) {
            checkMove(game->user->pos.y + 1,game->user->pos.x, game);
            game->user->stamina-= 3;
        }
        break;
    case KEY_LEFT:
        if (game->user->stamina > 20) {
            checkMove(game->user->pos.y,game->user->pos.x - 1, game);
            game->user->stamina-= 3;
        }
        break;
    case KEY_RIGHT:
        if (game->user->stamina > 20) {
            checkMove(game->user->pos.y,game->user->pos.x + 1, game);
            game->user->stamina-= 3;
        }
        break;
    case '1':
        if (game->user->sword.dano > 0){
            game->user->weapon = 0;
             handleInventory(game);
        }
        break;
    case '2':
        if (game->user->bow.dano > 0){    
            game->user->weapon = 1;
            handleInventory(game);
        }
        break;
    case '3':
        if (game->user->potion.dano > 0){
            game->user->weapon = 2;
            handleInventory(game);
        }
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
    case 'b':
        buyItem(game);
        break;
    case 'i':
        if(game->user->weapon==1)
            projetil('i',game);
            //checkDano_proj(game->mobs,game->seta);
        break;
    case 'j':
        if(game->user->weapon==1)
            projetil('j',game);
            //checkDano_proj(game->mobs,game->seta);
        break;
    case 'k':
    if(game->user->weapon==1)
            projetil('k',game);
            //checkDano_proj(game->mobs,game->seta);
        break;
    case 'l':
        if(game->user->weapon==1)
            projetil('l',game);
            //checkDano_proj(game->mobs,game->seta);
        break;
    case 32:
        if(game->user->weapon==0){
            if (game->user->stamina > 4) {
                useWeapon(0,game);
                game->user->stamina -= 7;
            }
        }
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

void healPlayer(player * user) {
    if (user->stamina < 496 && user->stamina >= 0)
        user->stamina += 4;
    if (user->vida < 500 && user->vida > 0)
        user->vida += 1;
}

void checkMove(int y, int x, gameState * game) {
    int margem = 3;
    if (game->map[y-margem][x-margem].walkable == 1) {
        clearFOV(game);
        movePlayer(y, x, game->user);
        makeFOV(game);
    }
}