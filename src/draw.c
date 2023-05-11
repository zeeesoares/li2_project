#include <rogue.h>

void drawMap(void)
{ 
  for (int y = 0; y < MAP_HEIGHT; y++)
  { 
    for (int x = 0; x < MAP_WIDTH; x++)
    { 
      mvaddch(y, x, mapinha[y][x].ch);
    } 
  } 
} 

void drawEntity(player* jogador)
{ 
  mvaddch(jogador->pos.y, jogador->pos.x, jogador->ch);
} 

void drawEverything(void)
{
  clear();
  drawMap();
  drawEntity(jogador);
} 