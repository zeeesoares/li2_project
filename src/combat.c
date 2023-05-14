#include <rogue.h>


void projetil(char direcao,gameState * game){
    game->seta->vx=game->user->pos.x;
    game->seta->vy=game->user->pos.y;
    game->seta->range=5;
    game->seta->visivel=FALSE;
    //
    if(direcao=='i'){
        game->seta->vy=-1;
        game->seta->vx=0;
        game->seta->visivel=TRUE;
    }

    if(direcao=='j'){
        game->seta->vx=-1;
        game->seta->vy=0;
        game->seta->visivel=TRUE;
    }

    if(direcao=='k'){
        game->seta->vy=1;
        game->seta->vx=0;
        game->seta->visivel=TRUE;

    }

    if(direcao=='l'){
        game->seta->vx=1;
        game->seta->vy=0;
        game->seta->visivel=TRUE;

    }

    for(int i=0;i<game->seta->range;i++){
        
        if(direcao=='i' || direcao=='k'){
            if (game->map[game->seta->pos.y][game->seta->pos.x].ch=='.'){
                //game->map[game->seta->pos.y][game->seta->pos.x].ch='|';
                if(game->seta->visivel==TRUE)
                    mvaddch(game->seta->pos.y + game->seta->vy,game->seta->pos.x + game->seta->vx,'|');
            }
            if (game->map[game->seta->pos.y][game->seta->pos.x].ch=='#'){
                //game->map[game->seta->pos.y-game->seta->vy][game->seta->pos.x-game->seta->vx].ch='|';
                if(game->seta->visivel==TRUE)
                    mvaddch(game->seta->pos.y - game->seta->vy,game->seta->pos.x - game->seta->vx,'|');
                break;
            }


        }


        if(direcao=='k' || direcao=='l'){
            if (game->map[game->seta->pos.y][game->seta->pos.x].ch=='.'){
                //game->map[game->seta->pos.y][game->seta->pos.x].ch='|';
                if(game->seta->visivel==TRUE)
                    mvaddch(game->seta->pos.y + game->seta->vy,game->seta->pos.x + game->seta->vx,'|');
            }
            if (game->map[game->seta->pos.y][game->seta->pos.x].ch=='#'){
                //game->map[game->seta->pos.y-game->seta->vy][game->seta->pos.x-game->seta->vx].ch='|';
                if(game->seta->visivel==TRUE)
                    mvaddch(game->seta->pos.y - game->seta->vy,game->seta->pos.x - game->seta->vx,'|');
                break;
            }
        }

    }




}


/*
fazer uma funcao que verifica se existe um mob perto do player returna 1 ou 0;
outra funcao void que dado o resultado da funcao da linha 12 em que encontra o mob e 
retira o dano da espada do player no campo de vida do mob;



*/











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

