#include <rogue.h>

int mapSetUp() {
    for(int i=5;i<45;i++){
        for(int j=5;j<140;j++){
            if (i == 5 || i == 44 || j == 5 || j == 139) {
                mvprintw(i,j,"#");
                //map[i][j] = '#';
            }
            else {
                mvprintw(i,j,".");
                //map[i][j] = '.';
            }
        }
    }
	return 0;
}
