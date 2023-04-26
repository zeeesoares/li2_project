#ifndef ROGUE_H
#define ROGUE_H

#define MAP_HEIGHT 50
#define MAP_WIDTH 150

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct position
{ 
  int x;
  int y;
} position;

typedef struct tile
{
  char ch;
  bool walkable;
} tile;

typedef struct room
{
  int height; 
  int width;
  position pos;
  position center;
} room;

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
void freeMap(void);
position setupmap(void);


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
player* createPlayer(position start_pos);


// functions room.c
room createRoom(int y, int x, int height, int width);
void addRoomToMap(room roomzinho);
void connectRoomCenters(position centerOne, position centerTwo);


// functions fov.c

#endif