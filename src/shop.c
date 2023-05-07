#include <rogue.h>

// setup da shop 
shop * shopSetup(tile ** map) {
    position start_pos = {rand() % 17 + 39,rand() % 17 + 25};
    shop * newShop = malloc(sizeof(shop));
    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    newShop->ch = '$';
    newShop->pos = start_pos;
    newShop->state = 0;
    newShop->act = 0;
    return newShop;
}

// verifica se o user esta na shop
void verificaShop(gameState * game) {
    game->shop->act = 0;
    int test = game->user->pos.x == game->shop->pos.x && game->user->pos.y == game->shop->pos.y;
    if (test) game->shop->act = 1;
    if (test && game->shop->state == 0) {
        drawShopInterface();
    }
    else if (test && game->shop->state == 1) {
        drawShopInterfaceSword();
    }
    else if (test && game->shop->state == 2) {
        drawShopInterfaceBows();
    }
    else if (test && game->shop->state == 3) {
        drawShopInterfacePotions();
    }
    else game->shop->state = 0;
}
