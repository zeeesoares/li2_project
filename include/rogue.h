#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define VISIBLE_COLOR 1
#define WALK_COLOR 2
#define SWORDC 3
#define BOWC 4
#define POTIONC 5

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
  int vida;
  int mana;

} player;
/*
typedef struct armas
{
  position pos;
  int maos;
  int espada;
  int arco;
  int pocao;
} armas;
*/

typedef struct seta
{
  position pos;
  int v;
  //int dano;
  int range;
} seta;

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
  int walkable;
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
  tile ** map;
  entity_mob * mob;
  //weapons * arma;
} gameState;


// functions map.c
//char ** mapSetUp();
tile ** mapSetUp();
tile ** createMap();
void freeMap(tile ** map);


// functions log.c
int logSetUp();
void invLog(int weapons, int count);

// functions player.c
void handleInput(int input, gameState * game);
void movePlayer(int x, int y, player * user);
void checkMove(int y, int x, gameState * game);
player * playerSetUp(position start_pos, tile ** map);

// functions mobs.c
entity_mob * mobsSetUp(position start_pos);

// functions draw.c
void drawEverything(gameState * game);
void drawMenu();
void drawPlayer(player * user);
void drawMap(tile ** map);
void drawInventory();
void drawMob(entity_mob * mob);
void drawStatus();
void draw_bars();
void drawInterface();
void drawCoins();

// functions engine.c
int ncursesSetUp();
int gameLoop(int input, gameState *);
int menuLoop(int input, gameState * game);
void closeGame(gameState *);

// functions room.c

//function inventory.c
void handleInventory(int input, gameState * game);
// functions fov.c

//functions combat.c
void projetil(char direcao,gameState * game);
#endif