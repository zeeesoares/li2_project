#include <rogue.h>


tile** createMapTiles(void)
{ 
  tile** tiles = calloc(MAP_HEIGHT, sizeof(tile*));

  for (int y = 5; y < 50; y++)
  { 
    tiles[y] = calloc(150, sizeof(tile));
    for (int x = 5; x < 150; x++)
    { 
      tiles[y][x].ch = '#';
      tiles[y][x].walkable = false;
    }
  } 

  return tiles;
} 

position setupMap(void)
{
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
    addRoomToMap(rooms[i]);
  }

  start_pos.y = rooms[0].center.y;
  start_pos.x = rooms[0].center.x;

  free(rooms);

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
