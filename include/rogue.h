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
  bool transparent;
} tile;

typedef struct
{
  int height; 
  int width;
  position pos;
  position center;
} Room;

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
tile** createMapTiles(void);
position setupmap(void);
void freeMap(void);




// functions log.c
int logSetUp();

// functions player.c
player* createPlayer(position start_pos);
void handleInput(int input);
void movePlayer(position newPos);

// functions draw.c
void drawMap(void);
void drawEntity(player* jogador);
void drawEverything(void);

// functions engine.c
bool ncursesSetUp(void);
void gameLoops(void);
void closeGames(void);


// functions room.c
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);



// functions fov.c
extern player* jogador;
extern tile** mapinha;
extern player* user;

#endif

