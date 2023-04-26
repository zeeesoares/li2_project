#include <rogue.h>

int logSetUp() {
    mvprintw(50, 5, "/ LOGS");
    return 0;
}

void invLog(int weapon, int count) {
    switch (weapon)
    {
    case 1:
        mvprintw(50+count,5,"ESPADA EQUIPADA!!!");
        break;
    case 2:
        mvprintw(50+count,5,"ARCO EQUIPADA!!!");
        break;
    case 3:
        mvprintw(50+count,5,"POCAO EQUIPADA!!!");
        break;
    
    default:
        break;
    }
    
}