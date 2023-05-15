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
 

               
