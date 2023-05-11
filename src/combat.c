#include <rogue.h>


void projetil(char direcao,gameState * game){

    

}


















/*
void *clean_projetil(void *arg) {
    gameState *game = (gameState *)arg;
    int y,x;
    y=game->data->y;
    x=game->data->x;
    
    //usleep(5000000);
    struct timespec req, rem;

    req.tv_sec = 5;             // Sleep for 5 seconds
    req.tv_nsec = 0;

    nanosleep(&req, &rem);
    
    game->map[y][x].ch = '.';
    pthread_exit(NULL);
}

void create_thread(gameState * game){
     pthread_t thread;

    pthread_create(&thread, NULL, clean_projetil, (void *)game);
    pthread_join(thread, NULL);
}








void projetil(char direcao,gameState * game){
    seta * setas;
    setas = malloc(sizeof(seta));
    setas->pos.x=5;
    setas->pos.y=5;
    setas->range=5;
    setas->vy=0;
    setas->vx=0;
    //int delay=100;
    int i=0;
    

    if (direcao=='i'){
        setas->vy=-1;
        setas->vx=0;
        setas->pos.x=game->user->pos.x-5;
        setas->pos.y=game->user->pos.y-6;
    }
    if (direcao=='j'){
        setas->vx=-1;
        setas->vy=0;
        setas->pos.x=game->user->pos.x-6;
        setas->pos.y=game->user->pos.y-5;
    }
    if (direcao=='k'){
        setas->vy=1;
        setas->vx=0;
        setas->pos.x=game->user->pos.x-5;
        setas->pos.y=game->user->pos.y-4;
    }
    if (direcao=='l'){
        setas->vx=1;
        setas->vy=0;
        setas->pos.x=game->user->pos.x-4;
        setas->pos.y=game->user->pos.y-5;
    }
        
    
            while(i<setas->range){
                if(direcao=='i' || direcao=='k'){
                    if(game->map[setas->pos.y][setas->pos.x].ch=='.'){
                        game->map[setas->pos.y][setas->pos.x].ch='|'; 
                    }
                    if(game->map[setas->pos.y][setas->pos.x].ch=='#'){
                        game->map[setas->pos.y-setas->vy][setas->pos.x-setas->vx].ch='|';
                        break;
                }
                }
                if(direcao=='j' || direcao=='l'){
                    if(game->map[setas->pos.y][setas->pos.x].ch=='.'){
                        game->map[setas->pos.y][setas->pos.x].ch='-'; 
                    }
                    if(game->map[setas->pos.y][setas->pos.x].ch=='#'){
                        game->map[setas->pos.y-setas->vy][setas->pos.x-setas->vx].ch='-';
                        break;
                }
                }


                

                if(direcao=='i'){
                    game->map[setas->pos.y+1][setas->pos.x].ch='.';
                    setas->pos.y--;
                }
                if(direcao=='j'){
                    game->map[setas->pos.y][setas->pos.x+1].ch='.';
                    setas->pos.x--;
                }
                if(direcao=='k'){
                    game->map[setas->pos.y-1][setas->pos.x].ch='.';
                    setas->pos.y++;
                }
                if(direcao=='l'){
                    game->map[setas->pos.y][setas->pos.x-1].ch='.';
                    setas->pos.x++;
                }

                i++;
            }
            game->data->y=setas->pos.y;
            game->data->x=setas->pos.x;
        
        
        
    
    free(setas);
}

*/

