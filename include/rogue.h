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

// functions map.c
int mapSetUp();

// functions log.c
int logSetUp();

// functions player.c
int handleInput(int input, player * user);
int movePlayer(int x, int y, player * user);
player * playerSetUp();

// functions draw.c


// functions engine.c


// functions room.c


// functions fov.c