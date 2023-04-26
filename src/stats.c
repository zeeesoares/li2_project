#include <rogue.h>


int health_Bar(int Dano,player * user){
    char vida[12];
    //vida[0]='|';
    for(int i=1;i<((user->vida)-Dano)/10;i++){
        vida[i]='#';
    }
    user->vida-=Dano;
    for(int i=((user->vida)-Dano)/10;i<11;i++){
        vida[i]='.';
    }
    vida[11]='|';

    mvprintw(7,180, "|    HP:");
    for(int i=0;i<12;i++){
        if((user->vida)-Dano<50){
            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(7,188+i,"%c",vida[i]);
            attroff(COLOR_PAIR(1));
        }
        if((user->vida)-Dano<10){
            init_pair(1,COLOR_RED,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(7,188+i,"%c",vida[i]);
            attroff(COLOR_PAIR(1));
        }
        else{
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(7,188+i,"%c",vida[i]);
            attroff(COLOR_PAIR(1));
        } 

    }
    return user;

}

int mana_Bar(int cast,player * user){
    char mana[12];
    //mana[0]='|';
    for(int i=0;i<((user->mana)-cast)/10;i++){
        mana[i]='#';
    }
    for(int i=((user->mana)-cast)/10;i<11;i++){
        mana[i]='.';
    }

    mana[11]='|';
    user->mana-=cast;

    mvprintw(7,180, "|    Mana:");
    for(int i=0;i<12;i++){
        if((user->mana)-cast<50){
            init_pair(1,COLOR_CYAN,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(7,188+i,"%c",mana[i]);
            attroff(COLOR_PAIR(1));
        }
        else{
            init_pair(1,COLOR_BLUE,COLOR_BLACK);
            attron(COLOR_PAIR(1));
            mvprintw(7,188+i,"%c",mana[i]);
            attroff(COLOR_PAIR(1));
        }    
    }
      

    return user;
}
