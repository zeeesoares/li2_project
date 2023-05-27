#include <rogue.h>

/*
- a104446 / Nuno Melo

Funções que altera arma que o user utiliza.
*/

void handleInventory(gameState * game) {
    switch (game->user->weapon)
    {
    case 0:
        game->user->color = COLOR_PAIR(SWORDC);
        break;
    case 1:
        game->user->color = COLOR_PAIR(BOWC);
        break;
    case 2:
        game->user->color = COLOR_PAIR(COLOR_CYAN);
        break;
    default:
        break;
    }
}