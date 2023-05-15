#include <rogue.h>

void projetil(char direcao,gameState * game){
    game->seta = malloc(sizeof(seta));
    
    game->seta->range=10;
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
            //mvaddch(y-vy, x-vx, '|');
            break;
        }
        if(game->map[y-3][x-3].ch=='.' && (direcao=='k' || direcao=='i')){
                //game->map[y][game->seta->pos.x].ch='|'; 
                //mvaddch(y,x,'|');
                mvaddch(y, x, '|');
                x+=vx;
                y+=vy;
                //refresh();
        }
        else    if(game->map[y-3][x-3].ch=='.' && direcao=='j'){
                    //game->map[y][game->seta->pos.x].ch='|'; 
                    //mvaddch(y,x,'|');
                    mvaddch(y, x, '<');
                    x+=vx;
                    y+=vy;
                    //refresh();
                }
        else    if(game->map[y-3][x-3].ch=='.' && direcao=='l'){
                    //game->map[y][game->seta->pos.x].ch='|'; 
                    //mvaddch(y,x,'|');
                    mvaddch(y, x, '>');
                    x+=vx;
                    y+=vy;
                    //refresh();
                }
        //loop que vou ver a pos da seta se é igual ao array dos mobs se encontrar uma posicao igual dá break
        i++;
        refresh();
        usleep(10000);
    }

}
 

               
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
