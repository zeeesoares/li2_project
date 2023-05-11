#include <rogue.h>

player* createPlayer(position start_pos)
{
  player* newPlayer = calloc(1, sizeof(player));

  newPlayer->posY = start_pos.y;
  newPlayer->posX = start_pos.x;
  newPlayer->ch = '@';

  return newPlayer;
}

void handleInput(int input)
{

  position newPos = { jogador->posY, jogador->posX };

  switch(input)
  {
    //move up
    case 'w':
      newPos.y--;
    //move down
    case 's':
      newPos.y++;
      break;
    //move left
    case 'a':
      newPos.x--;
      break;
    //move right
    case 'd':
      newPos.x++;
      break;
    default:
      break;
  }
}

void movePlayer(position newPos)
{ 
  if (mapinha[newPos.y][newPos.x].walkable)
  {
    jogador->posY = newPos.y;
    jogador->posX = newPos.x;
  }
}