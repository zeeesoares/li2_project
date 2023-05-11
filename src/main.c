#include <rogue.h>

player* jogador;

int main(void)
{

  position start_pos;

  cursesSetup();

  map = createMapTiles();

  start_pos = setupMap();
  jogador = createPlayer(start_pos);

  gameLoop();

  closeGame();

  return 0;
}