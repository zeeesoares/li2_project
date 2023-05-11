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



// FUNCOES DUNGEON


tile** createDungeonTiles()
{   
    int MAP_HEIGHT = 55;
    int MAP_WIDTH = 145;
    tile** tiles = calloc(MAP_HEIGHT, sizeof(tile*));

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        tiles[y] = calloc(MAP_WIDTH, sizeof(tile));
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            tiles[y][x].ch = '#';
            tiles[y][x].color = COLOR_PAIR(SEEN_COLOR);
            tiles[y][x].transparent = 0;
            tiles[y][x].visible = 1;
            tiles[y][x].seen = 0;
        }
    }

    return tiles;
}

position setupMapDungeons(tile ** dungeon)
{
    int MAP_HEIGHT = 55;
    int MAP_WIDTH = 145;
    int y, x, height, width, n_rooms;
    n_rooms =  (rand() % 11) + 5;
    Room* rooms = calloc(n_rooms, sizeof(Room));
    position start_pos;

    for (int i = 0; i < n_rooms; i++)
    {
        y = (rand() % (MAP_HEIGHT - 10)) + 1;
        x = (rand() % (MAP_WIDTH - 20)) + 1;
        height = (rand() % 7) + 3;
        width = (rand() % 15) + 5;
        rooms[i] = createRoom(y, x, height, width);
        addRoomToMap(rooms[i],dungeon);

        if (i > 0)
        {
            connectRoomCenters(rooms[i-1].center, rooms[i].center, dungeon);
        }
    }

    start_pos.y = rooms[0].center.y;
    start_pos.x = rooms[0].center.x;

    free(rooms);

    return start_pos;
}

/*
void freeMapDungeon(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(dungeon[y]);
    }
    free(dungeon);
}
*/

void freeMap(tile ** map)
{
    int rows = 55;
	for (int y = 0; y < rows; y++)
	{
		free(map[y]);
	}
	free(map);
}
