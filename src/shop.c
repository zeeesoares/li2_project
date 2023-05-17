#include <rogue.h>

// setup da shop 
shop * shopSetup(tile ** map) {
    position start_pos = {rand() % 17 + 39,rand() % 17 + 25};
    shop * newShop = malloc(sizeof(shop));
    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    newShop->visible = 0;
    newShop->ch = '$';
    newShop->pos = start_pos;
    newShop->state = 0;
    newShop->act = 0;
    newShop->sword = 1;
    newShop->bow = 1;
    newShop->potion = 1;
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

void selectItem(shop * shop, int i) {
    switch (i)
    {
    case 1:
        switch (shop->state)
            {
            case 1:
                if (shop->sword != 1)
                    shop->sword--;
                break;
            case 3:
                if (shop->potion != 1)
                    shop->potion--;
                break;
            default:
                break;
            }
        break;

    case 2:
        switch (shop->state)
            {
            case 1:
                if (shop->sword != 3)
                    shop->sword++;
                break;
            case 3:
                if (shop->potion != 3)
                    shop->potion++;
                break;
            default:
                break;
            }
        break;

    default:
        break;
    }
}


void buyItem(gameState * game) {
    if (game->shop->act == 1) {
        switch (game->shop->state)
        {
        case 1:
            switch (game->shop->sword)
            {
            case 1:
                if (game->user->coins >= 4000 && game->user->sword.get[0] != 1) {
                    game->user->coins -= 4000;
                    game->user->sword.dano = 24;
                    game->user->sword.class = 'B';
                    game->user->sword.get[0] = 1;
                }
                else {
                    game->user->sword.dano = 24;
                    game->user->sword.class = 'B';   
                }
                break;
            case 2:
                if (game->user->coins >= 5000 && game->user->sword.get[1] != 1) {
                    game->user->coins -= 5000;
                    game->user->sword.dano = 30;
                    game->user->sword.class = 'A';
                    game->user->sword.get[1] = 1;
                }
                else {
                    game->user->sword.dano = 30;
                    game->user->sword.class = 'A';
                }
                break;
            case 3:
                if (game->user->coins >= 7000 && game->user->sword.get[2] != 1) {
                    game->user->coins -= 7000;
                    game->user->sword.dano = 40;
                    game->user->sword.class = 'S';
                    game->user->sword.get[2] = 1;
                }
                else {
                    game->user->sword.dano = 40;
                    game->user->sword.class = 'S';
                }
                break;
            default:
                break;
            }
            break;
        case 2:
            if (game->user->coins >= 4000 &&  game->user->bow.get[0] != 1) {
                game->user->coins -= 4000;
                game->user->bow.dano = 20;
                game->user->bow.class = 'A';
                game->user->bow.get[0] = 1;
                }
            else {
                game->user->bow.dano = 20;
                game->user->bow.class = 'A';
            }
            break;
        case 3:
            switch (game->shop->potion)
            {
            case 1:
                if (game->user->coins >= 2000) {
                    game->user->coins -= 2000;
                    game->user->potion.dano = 20;
                    game->user->potion.class = 'A';
                    game->user->potion.get[0] += 1;
                }
                break;
            case 2:
                if (game->user->coins >= 1500) {
                    game->user->coins -= 1500;
                    game->user->potion.dano = 30;
                    game->user->potion.class = 'H';
                    game->user->potion.get[1] += 1;
                }
                break;
            case 3:
                if (game->user->coins >= 1500) {
                    game->user->coins -= 1500;
                    game->user->potion.dano = 30;
                    game->user->potion.class = 'S';
                    game->user->potion.get[2] += 1;
                }
                break;
            default:
                break;
            }
            break;
        default:
            break;
        
        }
    }
}
