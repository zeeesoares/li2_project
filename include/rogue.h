#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


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

typedef struct gameState
{
  position playerPos;
  player * user;
  char ** map;
} gameState;


// functions map.c
char ** mapSetUp();

// functions log.c
int logSetUp();

// functions player.c
void handleInput(int input, player * user);
void movePlayer(int x, int y, player * user);
void checkMove(int y, int x, player * user);
player * playerSetUp();

// functions draw.c
void drawEverything(char ** map);
void drawMap(char ** map);

// functions engine.c
int ncursesSetUp();
int gameLoop(int input, gameState *);
void closeGame(gameState *);

// functions room.c


// functions fov.c

#endif