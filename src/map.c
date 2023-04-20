#include <rogue.h>

int mapSetUp() {

    for(int i=5;i<45;i++){
        for(int j=5;j<140;j++){
            if (i == 5 || i == 44 || j == 5 || j == 139)
                mvprintw(i,j,"#");
            else
                mvprintw(i,j,".");
        }
    }
    mvprintw(5,180, "+-------------------+");
    mvprintw(6,180, "|                   |");
    mvprintw(7,180, "|    HP: 100/100    |");
    mvprintw(8,180, "|    Mana: 82/82    |");
    mvprintw(9,180, "|    XP: 11234      |");
    mvprintw(10,180,"|    LVL: 123       |");
    mvprintw(11,180,"|                   |");
    mvprintw(12,180,"+-------------------+");


    mvprintw(5,160,"+---------+");
    mvprintw(6,160,"|         |");
    mvprintw(7,160,"|  Coins  |");
    mvprintw(8,160,"|         |");
    mvprintw(9,160,"+---------+");


    mvprintw(14,160,"+---------------------------------------+");
    mvprintw(15,160,"| =Inventory=                           |");
    mvprintw(16,160,"|                                       |");
    mvprintw(17,160,"|  (1) Sword - /                        |");
    mvprintw(18,160,"|  (2) Bow - |>                         |");
    mvprintw(19,160,"|  (3) Potion (Poison) - o              |");
    mvprintw(20,160,"|                                       |");
    mvprintw(21,160,"+---------------------------------------+");

 
	return 0;
}
/*
    mvprintw(14,150,"  \``-.");
    mvprintw(15,150,"  )  _`-.");
    mvprintw(16,150," ,  : `. \)");
    mvprintw(17,150," : _   '  \'");
    mvprintw(18,150," ; *` _.   `--._");
    mvprintw(19,150," `-.-'          `-.");
    mvprintw(20,150,"   |       `       `.");
    mvprintw(21,150,"   :.       .        \ ");
    mvprintw(22,150,"   | \  .   :   .-'   .");
    mvprintw(23,150,"   :  )-.;  ;  /      :");
    mvprintw(24,150,"   :  ;  | :  :       ;-.");
    mvprintw(25,150,"   ; /   : |`-:     _ `- )");
    mvprintw(26,150,",-' /  ,-' ; .-`- .' `--'");
    mvprintw(27,150,"`--'   `---' `---'");
*/