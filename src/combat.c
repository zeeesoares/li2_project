#include <rogue.h>

/*
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

*/

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

*/







void projetil(char direcao,gameState * game){
    game->seta = malloc(sizeof(seta));
    
    game->seta->range=5;
    int i=0;
    game->seta->pos.x=game->user->pos.x;
    game->seta->pos.y=game->user->pos.y;    

    if (direcao=='i'){
        game->seta->vy=-1;
        game->seta->vx=0;
    }
    if (direcao=='j'){
        game->seta->vx=-1;
        game->seta->vy=0;
    }
    if (direcao=='k'){
        game->seta->vy=1;
        game->seta->vx=0;
    }
    if (direcao=='l'){
        game->seta->vx=1;
        game->seta->vy=0;
    }
            int vx=game->seta->vx;
            int vy=game->seta->vy;
            int y=game->seta->pos.y;
            int x=game->seta->pos.x;

    
            while(i<game->seta->range){
                if (game->map[y][x].ch == '#') {
                    mvprintw(y-vy, x-vx, "|");
                    break;
                }
                if(game->map[y][x].ch=='.'){
                        //game->map[y][game->seta->pos.x].ch='|'; 
                        //mvaddch(y,x,'|');
                        x+=vx;
                        y+=vy;
                        mvprintw(y, x, "|");
                        //refresh();
                }





                



               
                    
                    
                


                i++;
                
                refresh();
                usleep(1000000);
            }
            //game->data->y=setas->pos.y;
            //game->data->x=setas->pos.x;
        

        
    //mvprintw(y, x, "|");
    free(game->seta);
    
}
 

                /*
              
                if(direcao=='i'){
                    //game->map[setas->pos.y+1][setas->pos.x].ch='.';
                    y--;
                }
                if(direcao=='j'){
                    //game->map[setas->pos.y][setas->pos.x+1].ch='.';
                    x--;
                }
                if(direcao=='k'){
                    //game->map[setas->pos.y-1][setas->pos.x].ch='.';
                    y++;
                }
                if(direcao=='l'){
                    //game->map[setas->pos.y][setas->pos.x-1].ch='.';
                    x++;
                }
               
                  

                */



