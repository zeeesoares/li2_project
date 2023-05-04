#include <rogue.h>

player* jogador;



int main(void)
{

  position start_pos;

  ncursesSetUp();
  srand(time(NULL));


  mapinha = createMapTiles();
  start_pos = setupmap();
  jogador = createPlayer(start_pos);

  gameLoops();

  closeGames();

  return 0;
}
