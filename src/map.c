#include <rogue.h>

int mapSetUp() {
    srand(time(NULL));
    const int comprimento=45;
    const int largura=140;
    char map[comprimento][largura];
    int flag;
    WINDOW *mapa=newwin(comprimento,largura,0,0);
    for(int i=0;i<comprimento;i++){
        for(int j=0;j<largura;j++){
            flag=rand()%2;
            if (flag == 0){
                map[i][j]='.';
            }
            else{
                map[i][j]='#';
            }
              
        }
    }


    for(int i=0;i<comprimento;i++){
        for(int j=0;j<largura;j++){
            mvprintw(mapa,i,j,"%c",map[i][j]);
        }
        putchar('\n');

    }

    wrefresh(mapa);

	return 0;
}
