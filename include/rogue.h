#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// color pairs
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2


typedef struct position
{ 
  int x;
  int y;
} position;

typedef struct player
{
  position pos;
  int weapon;
  char ch;
  int color;
} player;

typedef struct entity_mob
{
  position pos;
  char ch;
  int type;
} entity_mob;

typedef struct tile 
{
  char ch;
  int color;
  int visible;
  bool walkable;
  bool transparent;
  bool visible;
  bool seen;
} tile;

typedef struct menu
{
  int jogar;
  int sair;
} menu;

typedef struct gameState
{
  menu modo;
  player * user;
  char ** map;
  entity_mob * mob;
} gameState;


// functions map.c
char ** mapSetUp();

// functions log.c
int logSetUp();
void invLog(int weapon, int count);

// functions player.c
void handleInput(int input, gameState * game);
void movePlayer(int x, int y, player * user);
void checkMove(int y, int x, gameState * game);
player * playerSetUp();

// functions mobs.c
entity_mob * mobsSetUp(position start_pos);

// functions draw.c
void drawEverything(gameState * game);
void drawMenu();
void drawPlayer(player * user);
void drawMap(char ** map);
void drawInventory();
void drawMob(entity_mob * mob);
void drawStatus();
void drawInterface();
void drawCoins();
void imprimeEspaco(int y, int x); 

// functions engine.c
int ncursesSetUp();
bool cursesSetup(void);
int gameLoop(int input, gameState *);
int menuLoop(int input, gameState * game);
void closeGame(gameState *);

// functions room.c

//function inventory.c
void handleInventory(int input, gameState * game);

// functions fov.c
void makeFOV(player *user);
void clearFOV(player *user);
int getDistance(position origem, position alvo);
bool isInMap (int y, int x);
bool lineOfSight(position origem, position alvo);
int getSign(int a);

#endif