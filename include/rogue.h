#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct position
{
  int y;
  int x;
} Position;

typedef struct entity
{
  Position pos;
  char ch;
} entity;

#endif

int mapSetUp();