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
            while (p < 30) {
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
        if (user->vida < 400 && user->potion.get[1] > 0) {
            user->vida += user->potion.dano;
            user->potion.get[1]--;
        }
        else if (user->potion.get[1] > 0) {
            user->vida = 500;
            user->potion.get[1]--;
        }
        break;
    case 'S':
        if (user->stamina < 400 && user->potion.get[2] > 0) {
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
    int numMobs = 30;
    for (int i = 0; i < numMobs; i++) {
        if (mobs[i].pos.y == user->pos.y && mobs[i].pos.x == user->pos.x) {
            if (user->vida > 0)
                user->vida -= mobs[i].dano;
        }
    }
}
void projetil(char direcao,gameState * game){
    game->seta = malloc(sizeof(seta));
    
    game->seta->range=10;
    game->seta->dano=10;
    int i=0;
    int y=0;
    int x=0;
    game->seta->pos.x=game->user->pos.x;
    game->seta->pos.y=game->user->pos.y;    

    if (direcao=='i'){
        game->seta->vy=-1;
        game->seta->vx=0;
        x=game->seta->pos.x;
        y=game->seta->pos.y-1;
    }
    if (direcao=='j'){
        game->seta->vx=-1;
        game->seta->vy=0;
        x=game->seta->pos.x-1;
        y=game->seta->pos.y;
    }
    if (direcao=='k'){
        game->seta->vy=1;
        game->seta->vx=0;
        x=game->seta->pos.x;
        y=game->seta->pos.y+1;
    }
    if (direcao=='l'){
        game->seta->vx=1;
        game->seta->vy=0;
        x=game->seta->pos.x+1;
        y=game->seta->pos.y;
    }

    int vx=game->seta->vx;
    int vy=game->seta->vy;
           
    while(i<game->seta->range){
        if (game->map[y-3][x-3].ch == '#') {
            break;
        }
        if(game->map[y-3][x-3].ch=='.' && (direcao=='k' || direcao=='i')){
                mvaddch(y, x, '|');
                x+=vx;
                y+=vy;
        }
        else    if(game->map[y-3][x-3].ch=='.' && direcao=='j'){
                    mvaddch(y, x, '<');
                    x+=vx;
                    y+=vy;
                }
        else    if(game->map[y-3][x-3].ch=='.' && direcao=='l'){
                    mvaddch(y, x, '>');
                    x+=vx;
                    y+=vy;
                }

        int numMobs = 30;
            for (int i = 0; i < numMobs; i++) {
            if ((game->mobs[i]).pos.y == y &&(game->mobs[i]).pos.x == x) {
                if ((game->mobs[i]).vida>0)
                    (game->mobs[i]).vida -= game->seta->dano;
                }
        }
        int numchest=8;
        for (int i = 0; i < numchest; i++) {
            if ((game->chest[i]).pos.y == y &&(game->chest[i]).pos.x == x) {
                if ((game->chest[i]).vida>0)
                    (game->chest[i]).vida -= game->seta->dano;
                }                
        }
        
        i++;
        refresh();
        usleep(10000);
    }
}

void useTocha(gameState* game) {
    if (game->numTochas > 0) {
        int y = game->user->pos.y;
        int x = game->user->pos.x;
        game->map[y-3][x-3].ch = 'i';
        makeFOV(game, 6);
        game->numTochas--;
    }
}