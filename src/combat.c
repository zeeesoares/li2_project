#include <rogue.h>

void useWeapon(int weapon, gameState * game) {
    switch (weapon)
    {
    case 0:
        useSword(game->mobs,game->user,game->chest);
        break;
    case 2:
        usePotion(game->user);
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

void usePotion(player * user) {
    switch (user->potion.class)
    {
    case 'A':
        /* code */
        break;
    case 'H':
        if (user->vida < 270 && user->potion.get[1] > 0) {
            user->vida += user->potion.dano;
            user->potion.get[1]--;
        }
        else if (user->potion.get[1] > 0) {
            user->vida = 300;
            user->potion.get[1]--;
        }
        break;
    case 'S':
        if (user->stamina < 470 && user->potion.get[2] > 0) {
            user->stamina += user->potion.dano;
            user->potion.get[2]--;
        }
        else if (user->potion.get[2] > 0) {
            user->stamina = 500;
            user->potion.get[2]--;
        }
        break;
    default:
        break;
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