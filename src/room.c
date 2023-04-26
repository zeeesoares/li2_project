#include <rogue.h>

tile** map;

room createRoom(int y, int x, int height, int width)
{
  room newRoom;

  newRoom.pos.y = y;
  newRoom.pos.x = x;
  newRoom.height = height;
  newRoom.width = width;
  newRoom.center.y = y + (int)(height / 2); // centro da room
  newRoom.center.x = x + (int)(width / 2); // centro da room

  return newRoom;
}

void addRoomToMap(room roomzinho)
{
  for (int y = roomzinho.pos.y; y < roomzinho.pos.y + roomzinho.height; y++)
  {
    for (int x = roomzinho.pos.x; x < roomzinho.pos.x + roomzinho.width; x++)
    {
      map[y][x].ch = '.';
      map[y][x].walkable = true;
    }
  }
}


tile** map;


tile** createTiles(void) // nao recebe argumentos nenhuns e retorna um array bidimencial (pointer para pointer para tiles)
{ 
  tile** tiles = calloc(50, sizeof(tile*)); // defenimos tiles e alloca na memorua uma aquantidade de tiles do tamanho do MAP_HEIGHT

  for (int y = 5; y < 50; y++)
  { 
    tiles[y] = calloc(150, sizeof(tile)); // Vemos todos os pointers que acabaram de ser alocados, e para cada um deles é allocado um numero de tiles igual a MAP_WIDTH
    for (int x = 5; x < 150; x++) // neste loop acedece-se a cada tile para inicializar a sua variavel. # representa parede e walkable esta a false para o player nao andar por paredes
    { 
      tiles[y][x].ch = '#';
      tiles[y][x].walkable = false;
    }
  } 

  return tiles;
} 

position setupmap(void)
{
  int y, x, height, width, n_rooms;
  n_rooms =  (rand() % 11) + 5;
  room* rooms = calloc(n_rooms, sizeof(room));
  position start_pos; // localicacao inicial do player

  for (int i = 0; i < n_rooms; i++)
  {
    y = (rand() % (MAP_HEIGHT - 10)) + 5;
    x = (rand() % (MAP_WIDTH - 20)) + 5;
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

void freeMap(void) // funcao usada para dar free a cada linha de arrays antes de finalmente dar free ao mapa em si
{ 
  for (int y = 5; y < 50; y++)
  { 
    free(map[y]);
  } 
  free(map);
} 