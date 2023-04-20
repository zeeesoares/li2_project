#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct position
{ 
  int x;
  int y;
} position;

typedef struct player
{
  int posX;
  int posY;
  char ch;
} player;

#endif

int mapSetUp();

int logSetUp();

int handleInput(int input, player * user);
int movePlayer(int x, int y, player * user);

player * playerSetUp();