#include <rogue.h>

/*
- a104446 / Nuno Melo

Funções relacionadas à produção do mapa e organização de mapa.
*/
tile ** createMap() {
    int rows = 50;
	int cols = 145;
    tile ** tiles = calloc(rows,sizeof(tile *));

    for (int i = 0; i < rows; i++) {
        tiles[i] = calloc(cols, sizeof(tile));
        for (int j = 0; j < cols; j++) {
			tiles[i][j].ch = '.';
			tiles[i][j].color = COLOR_PAIR(TRANSPARENT_COLOR);
			tiles[i][j].seen = 0;
            tiles[i][j].walkable = 1;
			tiles[i][j].visible = 0;
            tiles[i][j].visibleT = 0;
            tiles[i][j].transparent = 1;
        }
    }
    return tiles;
}

/*
- a104446 / Nuno Melo

Funções relacionadas à produção do mapa e organização de mapa.
*/
tile ** mapSetUp(tile ** tilesInit) {
    int rows = 50;
	int cols = 145;
    // preencher o array bidimensional com caracteres aleatórios
    int count = 0;
    srand(time(NULL));

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                tilesInit[i][j].ch = '#';
                tilesInit[i][j].walkable = 0;
            }
            else {
                int r = rand()%4;
                if(r ==0 ) {
                    tilesInit[i][j].ch = '#';
                    tilesInit[i][j].walkable = 0;
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
                    tile hold= tilesInit[i][j+1];
                    tilesInit[i][j+1]=tilesInit[i][j+2];
                    tilesInit[i][j+2]=hold;
                }
                if((tilesInit[i][j].ch<tilesInit[i+1][j].ch)&& (tilesInit[i+1][j].ch>tilesInit[i+2][j].ch)){
                    tile hold=tilesInit[i+1][j];
                    tilesInit[i+1][j]=tilesInit[i+2][j];
                    tilesInit[i+2][j]=hold;
                }
            }
        }
        for(int i = 1; i < rows-6; i++) {
            for(int j = 1; j < cols-6; j++) {
                if((tilesInit[i][j].ch<tilesInit[i][j+1].ch)&& (tilesInit[i][j+1].ch>tilesInit[i][j+3].ch)){
                    tile hold=tilesInit[i][j+1];
                    tilesInit[i][j+1]=tilesInit[i][j+3];
                    tilesInit[i][j+3]=hold;
                }
                if((tilesInit[i][j].ch<tilesInit[i+1][j].ch)&& (tilesInit[i+1][j].ch>tilesInit[i+4][j].ch)){
                    tile hold=tilesInit[i+1][j];
                    tilesInit[i+1][j]=tilesInit[i+4][j];
                    tilesInit[i+4][j]=hold;
                }
            }
        }
        
    
        for(int i = 1; i < rows-4; i++) {
            for(int j = 1; j < cols-4; j++) {
                if((tilesInit[i][j].ch<tilesInit[i][j+1].ch)&& (tilesInit[i][j+1].ch>tilesInit[i][j+3].ch)){
                    tile hold=tilesInit[i][j+1];
                    tilesInit[i][j+1]=tilesInit[i][j+3];
                    tilesInit[i][j+3]=hold;
                }
                if((tilesInit[i][j].ch<tilesInit[i+1][j].ch)&& (tilesInit[i+1][j].ch>tilesInit[i+3][j].ch)){
                    tile hold=tilesInit[i+1][j];
                    tilesInit[i+1][j]=tilesInit[i+3][j];
                    tilesInit[i+3][j]=hold;
                }
            }
        }
    }

    for(int i = 2; i < rows-2; i++) {
        for(int j = 2; j < cols-2; j++) {
            if((tilesInit[i][j].ch<tilesInit[i][j+1].ch) && tilesInit[i][j].ch<tilesInit[i][j-1].ch && tilesInit[i][j].ch<tilesInit[i+1][j].ch && tilesInit[i][j].ch<tilesInit[i-1][j].ch) {
                tilesInit[i][j].ch = '.';
                tilesInit[i][j].walkable = 1;
            }
        }
    }
    for(int i = 1; i < 2; i++) {
        for(int j = 1; j < cols-2; j++) {
            if((tilesInit[i][j].ch<tilesInit[i][j+1].ch) && tilesInit[i][j].ch<tilesInit[i][j-1].ch && tilesInit[i][j].ch<tilesInit[i+1][j].ch) {
                tilesInit[i][j].walkable = 1;
                tilesInit[i][j].ch = '.';
            }
        }
    }
    for(int i = rows - 2; i < rows; i++) {
        for(int j = 1; j < cols-2; j++) {
            if((tilesInit[i][j].ch<tilesInit[i][j+1].ch) && tilesInit[i][j].ch<tilesInit[i][j-1].ch && tilesInit[i][j].ch<tilesInit[i-1][j].ch) {
                tilesInit[i][j].ch = '.';
                tilesInit[i][j].walkable = 1;
            }
        }
    }
    return tilesInit;
}

/*
- a104446 / Nuno Melo

Funções relacionadas à produção do mapa e organização de mapa.
*/
void freeMap(tile ** map)
{
    int rows = 50;
	for (int y = 0; y < rows; y++)
	{
		free(map[y]);
	}
	free(map);
}
