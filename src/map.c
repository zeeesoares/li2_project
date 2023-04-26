#include <rogue.h>

int mapSetUp() {
    int rows = 40;
    int cols = 135;
    float percBlocks = 0.40;
    int totalBlocks = rows*cols;
    float maxCard = percBlocks *totalBlocks;
    int numCards = 0; 

    // alocar memória para o array bidimensional
    char **map = (char **) malloc(rows * sizeof(char *));
    for(int i = 0; i < rows; i++) {
        map[i] = (char *) malloc(cols * sizeof(char));
    }

    // preencher o array bidimensional com caracteres aleatórios
    int count = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (i == 0| j == 0| i == 39 | j == 134) {
                map[i][j] = '#';
            }
            else {
                int r = rand()%4;
                if(r ==0 ) {
                    map[i][j] = '#';
                    count++;
                } 
                else {
                map[i][j] = '.';
                }
            }
        }
    }
    for(int k=0;k<5;k++){
        for(int i = 1; i < rows-4; i++) {
            for(int j = 1; j < cols-4; j++) {
                if((map[i][j]<map[i][j+1])&& (map[i][j+1]>map[i][j+2])){
                    char hold=map[i][j+1];
                    map[i][j+1]=map[i][j+2];
                    map[i][j+2]=hold;
                }
                if((map[i][j]<map[i+1][j])&& (map[i+1][j]>map[i+2][j])){
                    char hold=map[i+1][j];
                    map[i+1][j]=map[i+2][j];
                    map[i+2][j]=hold;
                }
            }
        }
    
    
         for(int i = 1; i < rows-4; i++) {
            for(int j = 1; j < cols-4; j++) {
                if((map[i][j]<map[i][j+1])&& (map[i][j+1]>map[i][j+3])){
                    char hold=map[i][j+1];
                    map[i][j+1]=map[i][j+3];
                    map[i][j+3]=hold;
                }
                if((map[i][j]<map[i+1][j])&& (map[i+1][j]>map[i+3][j])){
                    char hold=map[i+1][j];
                    map[i+1][j]=map[i+3][j];
                    map[i+3][j]=hold;
                }
            }
        }
    }
    // imprimir o mapa
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            mvprintw(i+5, j+5, "%c", map[i][j]);
        }
    }
    return 0;
}