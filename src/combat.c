#include <rogue.h>

void useWeapon(int weapon, gameState * game) {
    switch (weapon)
    {
    case 0:
        useSword(game->mobs,game->user,game->chest);
        break;
    
    default:
        break;
    }
}

void useSword(entity_mob *mobs, player *user, chest * chests) {
    int i = user->pos.y - 2;
    int j = user->pos.x - 2;
    for (; i < user->pos.y + 2; i++) {
        for (int k = j; k < j + 5; k++) {
            int p = 0;
            while (p < 15) {
                if ((mobs+p)->pos.y == i && (mobs+p)->pos.x == k && (mobs+p)->vida > 0) {
                    (mobs+p)->vida -= user->sword.dano;
                    if ((mobs+p)->vida < 0)
                        (mobs+p)->vida = 0; 
                }
                if ((chests+p)->pos.y == i && (chests+p)->pos.x == k && (chests+p)->vida > 0) {
                    (chests+p)->vida -= user->sword.dano;
                    if ((chests+p)->vida < 0)
                        (chests+p)->vida = 0; 
                }
                p++;
            }
        }
    }
}

void checkDano(entity_mob *mobs, player *user) {
    int numMobs = 12;
    for (int i = 0; i < numMobs; i++) {
        if (mobs[i].pos.y == user->pos.y && mobs[i].pos.x == user->pos.x) {
            if (user->vida > 0)
                user->vida -= mobs[i].dano;
        }
    }
}