#include <rogue.h>

int mapSetUp() {
    char map[10][10];


    for(int i=12;i<20;i++){
        for(int j=12;j<30;j++){
            mvprintw(i,j,"#");    
        }
    }
        

    mvprintw(5,180, "HP: 100/100");
    mvprintw(6,180, "CHAKRA: 82/100");
    mvprintw(7,180, "XP: 436");
    mvprintw(8,180, "LVL: 27");
	return 0;
}

