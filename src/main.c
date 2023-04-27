#include <rogue.h>

player* jogador;
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

int main(void)
{

	position start_pos;

  ncursesSetUp();

  map = createTiles();
  start_pos = setupmap();
  jogador = createPlayer(start_pos);

  //gameLoop();

  //closeGame();

  return 0;
}