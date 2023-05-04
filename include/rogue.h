#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define VISIBLE_COLOR 1
#define SEEN_COLOR 2
#define SWORDC 3
#define BOWC 4
#define POTIONC 5
#define MOBCOLOR 6

typedef struct position
{ 
  int x;
  int y;
} position;

typedef struct player
{
  position pos;
  int weapon;
  int color;
  char ch;
} player;

typedef struct entity_mob
{
  position pos;
  char ch;
  int type;
} entity_mob;

typedef struct mob_node {
    entity_mob *mob;
    struct mob_node *next;
} mob_node;

typedef struct tile 
{
  char ch;
  int color;
  int visible;
  int seen;
  int transparent;
} tile;

typedef struct menu
{
  int jogar;
  int sair;
} menu;

typedef struct Room
{
  int height; 
  int width;
  position pos;
  position center;
} Room;

typedef struct Shop
{
  position pos;
  char ch;
} shop;

typedef struct gameState
{
  menu modo;
  player * user;
  tile ** map;
  entity_mob * mob;
  shop * shop;
} gameState;


// functions map.c
tile ** mapSetUp();
tile ** createMap();
void freeMap(tile ** map);


// functions log.c
int logSetUp();
void invLog(int weapon, int count);

// functions player.c
void handleInput(int input, gameState * game);
void movePlayer(int x, int y, player * user);
void checkMove(int y, int x, gameState * game);
player * playerSetUp(tile ** map);

// functions mobs.c
entity_mob * mobsSetUp(tile ** map);

// functions draw.c
void drawEverything(gameState * game);
void drawMenu();
void drawPlayer(player * user);
void drawMap(tile ** map);
void drawInventory();
void drawMob(entity_mob * mob, tile ** map);
void drawShop(shop * shop, tile ** map);
void drawStatus();
void drawInterface();
void drawCoins();

// functions engine.c
int ncursesSetUp();
int gameLoop(int input, gameState *);
int menuLoop(int input, gameState * game);
void closeGame(gameState *);

// functions room.c

//function inventory.c
//void handleInventory(int input, gameState * game);

// functions fov.c
void makeFOV(gameState * game);
void clearFOV(gameState * game);
int getdistance (position origem, position alvo);
int isInMap(int y, int x);

// functions shop.c
shop * shopSetup(tile ** map);
void verificaShop(gameState * game);


#endif