#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define VISIBLE_COLOR 1
#define SEEN_COLOR 2
#define SWORDC 3
#define BOWC 4
#define POTIONC 5
#define MOBCOLOR 6
#define TRANSPARENT_COLOR 7

typedef struct position
{ 
  int x;
  int y;
} position;

typedef struct item
{
  char class;
  int dano;
  int get[3];
} item;

typedef struct player
{
  position pos;
  int vida;
  int stamina;
  int weapon;
  item sword;
  item bow;
  item potion;
  int coins;
  int color;
  char ch;

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

typedef struct projetil
{
  position pos;
  int vx;
  int vy;
  int dano;
  int range;
  int visivel;
} seta;




typedef struct entity_mob
{
  position pos;
  char ch;
  int vida;
  int type;
} entity_mob;

typedef struct mob_node {
    entity_mob * mob;
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
typedef struct 
{
  int x;
  int y;
  
}datas;

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
  int act;
  int state;
  int sword;
  int bow;
  int potion;
} shop;

typedef struct gameState
{
  menu modo;
  player * user;
  tile ** map;
  mob_node * mobs;
  entity_mob * mob;
  //weapons * arma;
  //seta * setas;
  datas * data;
  shop * shop;
  seta * seta;
} gameState;


// functions map.c
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
player * playerSetUp(tile ** map);

// functions mobs.c
entity_mob * mobsSetUp(tile ** map);
void add_mob_to_list(mob_node **list, tile **map);
mob_node * createMobLList(int numMobs, tile ** map);
void freeMobList(mob_node *list);
void freeMobNode(mob_node *node);

// functions draw.c
void drawEverything(gameState * game);
void drawMenu();
void drawPlayer(player * user);
void drawMap(tile ** map);
void drawInventory(player * user);
void drawMob(entity_mob * mob, tile ** map);
void drawMobs(mob_node *mobs, tile **map);
void drawShop(shop * shop, tile ** map);
void drawShopInterface();
void drawStatus(gameState * game);
void drawInterface();
void drawShopInterfaceSword();
void drawShopInterfaceBows();
void drawShopInterfacePotions();
void drawCoins(player * user);
void drawSelected(shop * shop);

// functions engine.c
int ncursesSetUp();
int gameLoop(int input, gameState *);
int menuLoop(int input, gameState * game);
void closeGame(gameState *);

// functions room.c

//function inventory.c
//void handleInventory(gameState * game);

//void handleInventory(int input, gameState * game);

// functions fov.c
void makeFOV(gameState * game);
void clearFOV(gameState * game);
int getdistance (position origem, position alvo);
int isInMap(int y, int x);
int lineOfSight(tile ** map, position origem, position alvo);

// functions shop.c
shop * shopSetup(tile ** map);
void verificaShop(gameState * game);
void selectItem(shop * shop, int i);
void buyItem(gameState * game);

//functions combat.c
//void projetil(char direcao,gameState * game);
//void *clean_projetil(void *arg);
//void create_thread(gameState * game);
#endif