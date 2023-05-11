#include <rogue.h>

tile** createMapTiles(void)
{ 
  tile** tiles = calloc(MAP_HEIGHT, sizeof(tile*));

  for (int y = 0; y < MAP_HEIGHT; y++)
  { 
    tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
    for (int x = 0; x < MAP_WIDTH; x++)
    { 
      tiles[y][x].ch = '#';
      tiles[y][x].walkable = false;
    }
  } 

  return tiles;
} 

position setupMap(void)
{
  position start_pos = { 10, 50 };

  for (int y = 5; y < 15; y++)
  {
    for (int x = 40; x < 60; x++)
    {
      mapinha[y][x].ch = '.';
      mapinha[y][x].walkable = true;
    }
  }

  return start_pos;
}

void freeMap(void)
{ 
  for (int y = 0; y < MAP_HEIGHT; y++)
  { 
    free(mapinha[y]);
  } 
  free(mapinha);
} 