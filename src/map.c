#include <rogue.h>


tile ** createMap() {
    int rows = 55;
	int cols = 145;
    tile ** tiles = calloc(rows,sizeof(tile *));

    for (int i = 0; i < rows; i++) {
        tiles[i] = calloc(cols, sizeof(tile));
        for (int j = 0; j < cols; j++) {
			tiles[i][j].ch = '.';
			tiles[i][j].color = COLOR_PAIR(TRANSPARENT_COLOR);
			tiles[i][j].seen = 1;
			tiles[i][j].visible = 0;
            tiles[i][j].transparent = 0;
        }
    }
    return tiles;
}

tile ** mapSetUp(tile ** tilesInit) {
    int rows = 55;
	int cols = 145;
    // preencher o array bidimensional com caracteres aleatórios
    int count = 0;
    srand(time(NULL));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                tilesInit[i][j].ch = '#';
            }
            else {
                int r = rand()%4;
                if(r ==0 ) {
                    tilesInit[i][j].ch = '#';
                    count++;
                } 
                else {
                tilesInit[i][j].ch = '.';
                }
            }
        }
    }
    for(int k=0;k<5;k++){
        for(int i = 1; i < rows-4; i++) {
            for(int j = 1; j < cols-4; j++) {
                if((tilesInit[i][j].ch<tilesInit[i][j+1].ch)&& (tilesInit[i][j+1].ch>tilesInit[i][j+2].ch)){
                    char hold=tilesInit[i][j+1].ch;
                    tilesInit[i][j+1].ch=tilesInit[i][j+2].ch;
                    tilesInit[i][j+2].ch=hold;
                }
                if((tilesInit[i][j].ch<tilesInit[i+1][j].ch)&& (tilesInit[i+1][j].ch>tilesInit[i+2][j].ch)){
                    char hold=tilesInit[i+1][j].ch;
                    tilesInit[i+1][j].ch=tilesInit[i+2][j].ch;
                    tilesInit[i+2][j].ch=hold;
                }
            }
        }
        for(int i = 1; i < rows-6; i++) {
            for(int j = 1; j < cols-6; j++) {
                if((tilesInit[i][j].ch<tilesInit[i][j+1].ch)&& (tilesInit[i][j+1].ch>tilesInit[i][j+3].ch)){
                    char hold=tilesInit[i][j+1].ch;
                    tilesInit[i][j+1].ch=tilesInit[i][j+3].ch;
                    tilesInit[i][j+3].ch=hold;
                }
                if((tilesInit[i][j].ch<tilesInit[i+1][j].ch)&& (tilesInit[i+1][j].ch>tilesInit[i+4][j].ch)){
                    char hold=tilesInit[i+1][j].ch;
                    tilesInit[i+1][j].ch=tilesInit[i+4][j].ch;
                    tilesInit[i+4][j].ch=hold;
                }
            }
        }
        
    
        for(int i = 1; i < rows-4; i++) {
            for(int j = 1; j < cols-4; j++) {
                if((tilesInit[i][j].ch<tilesInit[i][j+1].ch)&& (tilesInit[i][j+1].ch>tilesInit[i][j+3].ch)){
                    char hold=tilesInit[i][j+1].ch;
                    tilesInit[i][j+1].ch=tilesInit[i][j+3].ch;
                    tilesInit[i][j+3].ch=hold;
                }
                if((tilesInit[i][j].ch<tilesInit[i+1][j].ch)&& (tilesInit[i+1][j].ch>tilesInit[i+3][j].ch)){
                    char hold=tilesInit[i+1][j].ch;
                    tilesInit[i+1][j].ch=tilesInit[i+3][j].ch;
                    tilesInit[i+3][j].ch=hold;
                }
            }
        }
    }

    for(int i = 2; i < rows-2; i++) {
        for(int j = 2; j < cols-2; j++) {
            if((tilesInit[i][j].ch<tilesInit[i][j+1].ch) && tilesInit[i][j].ch<tilesInit[i][j-1].ch && tilesInit[i][j].ch<tilesInit[i+1][j].ch && tilesInit[i][j].ch<tilesInit[i-1][j].ch) {
                tilesInit[i][j].ch = '.';
            }
        }
    }
    for(int i = 1; i < 2; i++) {
        for(int j = 1; j < cols-2; j++) {
            if((tilesInit[i][j].ch<tilesInit[i][j+1].ch) && tilesInit[i][j].ch<tilesInit[i][j-1].ch && tilesInit[i][j].ch<tilesInit[i+1][j].ch) {
                tilesInit[i][j].ch = '.';
            }
        }
    }
    for(int i = rows - 2; i < rows; i++) {
        for(int j = 1; j < cols-2; j++) {
            if((tilesInit[i][j].ch<tilesInit[i][j+1].ch) && tilesInit[i][j].ch<tilesInit[i][j-1].ch && tilesInit[i][j].ch<tilesInit[i-1][j].ch) {
                tilesInit[i][j].ch = '.';
            }
        }
    }
    return tilesInit;
}

void freeMap(tile ** map)
{
    int rows = 55;
	for (int y = 0; y < rows; y++)
	{
		free(map[y]);
	}
	free(map);
}
