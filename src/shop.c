#include <rogue.h>

// setup da shop 
shop * shopSetup(tile ** map) {
    position start_pos = {rand() % 17 + 39,rand() % 17 + 25};
    shop * newShop = malloc(sizeof(shop));
    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    newShop->ch = '$';
    newShop->pos = start_pos;
    return newShop;
}

// verifica se o user esta na shop
void verificaShop(gameState * game) {
    if (game->user->pos.x == game->shop->pos.x && game->user->pos.y == game->shop->pos.y) {
        drawShopInterface();
    }
}