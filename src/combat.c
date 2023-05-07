#include <rogue.h>


void projetil(char direcao,gameState * game){
    int range=15;
    int v=1;
    int distance;
    int old_x;
    int old_y;
    seta setas;
    if (direcao=='i'){
        setas.pos.x=game->user->pos.x-5;
        setas.pos.y=game->user->pos.y-6;
        old_x=game->user->pos.x;
        old_y=game->user->pos.y;
        while(old_y<old_y+range){
            if(game->map[setas.pos.y][setas.pos.x].ch=='.'){
                game->map[setas.pos.y][setas.pos.x].ch='|'; 
                game->map[setas.pos.y+1][setas.pos.x].ch='.';
            }
            if(game->map[setas.pos.y][setas.pos.x].ch=='#'){
                game->map[setas.pos.y+1][setas.pos.x].ch='.';
                break;
            }
            else break;
            old_y++;
            setas.pos.y--;
            usleep(100000);
        }
    }
    if (direcao=='j'){
        setas.pos.x=game->user->pos.x-1;
        setas.pos.y=game->user->pos.y;
        while(setas.pos.x<setas.pos.x-range){
            if(game->map[setas.pos.y][setas.pos.x].ch=='.'){
                game->map[setas.pos.y][setas.pos.x].ch='|'; 
                game->map[setas.pos.y][setas.pos.x+1].ch='.';
            }
            else break;

            setas.pos.x--;

            usleep(1000000);
        }
    }
    if (direcao=='k'){
        setas.pos.x=game->user->pos.x;
        setas.pos.y=game->user->pos.y-1;
        while(setas.pos.y<setas.pos.y-range){
            if(game->map[setas.pos.y][setas.pos.x].ch=='.'){
                game->map[setas.pos.y][setas.pos.x].ch='|'; 
                game->map[setas.pos.y+1][setas.pos.x].ch='.';
            }
            else break;
            usleep(1000000);
        }
    }
    if (direcao=='l'){
        setas.pos.x=game->user->pos.x;
        setas.pos.y=game->user->pos.y-1;
        while(setas.pos.y<setas.pos.y-range){
            if(game->map[setas.pos.y][setas.pos.x].ch=='.'){
                game->map[setas.pos.y][setas.pos.x].ch='|'; 
                game->map[setas.pos.y+1][setas.pos.x].ch='.';
            }
            else break;
            usleep(1000000);
        }
    }
    
}




int getdistance (position origem, position alvo) {
    double dx;
    double dy;
    int distance;
    dx = alvo.x - origem.x;
    dy = alvo.y - origem.y;
    distance = floor(sqrt((dx * dx) + (dy * dy)));
    return distance;
}