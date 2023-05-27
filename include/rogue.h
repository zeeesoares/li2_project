#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>

// cores para os elementos dos jogos
#define VISIBLE_COLOR 1 
#define SEEN_COLOR 2
#define SWORDC 3
#define BOWC 4
#define POTIONC 5
#define MOBCOLOR 6
#define TRANSPARENT_COLOR 7


// struct para guardar posiçoes dos diferentes elementos
typedef struct position
{ 
  int x;
  int y;
} position;

// struct para os items/consumiveis
typedef struct item
{
  char class;
  int dano;
  int get[3];
} item;

// struct para o user/player do jogo
typedef struct player
{
  position pos;
  int vida;
  int stamina;
  int lanterna;
  int weapon;
  item sword;
  item bow;
  item potion;
  int coins;
  int color;
  char ch;
} player;

// struct para os mobs/monstros do jogo
typedef struct entity_mob
{
  position pos;
  int id;
  int dano;
  int visible;
  int visibleT;
  char *nome;
  char ch;
  int vida;
  int coins;
  int type;
} entity_mob;

// struct para cada bloco do mapa (tile)
typedef struct tile 
{
  char ch;
  int color;
  int walkable;
  int visible;
  int visibleT;
  int seen;
  int transparent;
} tile;


// struct para o menu inicial
typedef struct menu
{
  int jogar;
  int sair;
  int tutorial;
  int death;
  int victory;
} menu;

// struct para a room (dungeon)
typedef struct Room
{
  int height; 
  int width;
  position pos;
  position center;
} Room;

// struct para a shop
typedef struct Chest
{
  position pos;
  char ch;
  int visible;
  int coins;
  int vida;
} chest;

// struct para a shop
typedef struct Shop
{
  position pos;
  char ch;
  int visible;
  int act;
  int state;
  int sword;
  int bow;
  int potion;
} shop;

typedef struct projetil
{
  position pos;
  int vx;
  int vy;
  int dano;
  int range;
  int visivel;
} seta;

typedef struct bomba {
  position pos;
  char ch;
} bomba;

// struct PRINCIPAL responsavel por enviar todos os dados do jogo as funcoes da engine.c
typedef struct gameState
{
  menu modo;
  int state;
  int numTochas;
  player * user;
  tile ** map;
  entity_mob * mobs;
  chest * chest;
  shop * shop;
  seta * seta;
  bomba * bomba;
} gameState;

//////////////////////////////// TYPES AND FUNCTIONS ///////////////////////////////////

// functions map.c
tile ** mapSetUp();
tile ** createMap();
void freeMap(tile ** map);

// functions player.c
player *createPlayerArray(int numPlayers, tile **map);
void handleInput(int input, gameState * game);
void movePlayer(int x, int y, player * user);
void checkMove(int y, int x, gameState * game);
player *playerSetUp(tile ** map);
void healPlayer(player * user);
int checkPlayer(player * user);

// functions mobs.c
entity_mob * mobsSetUp(tile ** map);
void isMobVisible (shop * shop,entity_mob * mobs, tile ** map, chest * chest);
void moveMobs(entity_mob * mobs,tile ** map,player * user);
void moveMob(entity_mob * mob, tile ** map);
entity_mob *createMobArray(int numMobs, tile **map);
chest *createChestArray(int numChests, tile **map);
void freeMobs(entity_mob * mobs);
void freeChests(chest *chests);
char defineMobChar(int name);
int defineMobHealth(int name);
int defineMobCoins(int name);
int defineMobDano(int name);
void moveMobTowardsUser(entity_mob * mob, player * user, tile** map);
int contaMobs(entity_mob mobs[]);

// functions draw.c
void drawEverything(gameState * game);
void drawMenu();
void drawTutorial ();
void drawDeath ();
void drawVictory ();
void drawbomb(gameState * game);
void drawPlayer(player * user);
void drawMap(tile ** map);
void drawInventory(player * user, int numTochas);
void drawMob(entity_mob mob, tile ** map);
void drawMobs(entity_mob *mobs, tile **map);
void drawShop(shop * shop, tile ** map);
void drawShopInterface();
void drawInterfaceMobStatus(gameState * game);
void drawStatus(gameState * game, int num);
void drawInterface(shop * shop);
void drawShopInterfaceSword();
void drawShopInterfaceBows();
void drawShopInterfacePotions();
void drawCoins(player * user);
void drawSelected(shop * shop);
void vericaCoins(player * user, entity_mob * mobs, chest * chests);
void drawChests(chest chest[], tile **map); 
void drawChest(chest chest, tile **map);

// functions engine.c
int ncursesSetUp();
int gameLoop(int input, gameState *);
int menuLoop(int input, gameState * game);
void closeGame(gameState *);

//function inventory.c
void handleInventory(gameState * game);

// functions fov.c
void makeFOV(gameState * game, int raio);
void clearFOV(gameState * game, int raio);
int getdistance (position origem, position alvo);
int isInMap(int y, int x);
int lineOfSight(tile ** map, position origem, position alvo);

// functions shop.c
shop * shopSetup(tile ** map);
void verificaShop(gameState * game);
void selectItem(shop * shop, int i);
void buyItem(gameState * game);

// functions combat.c
void useWeapon(int weapon, gameState * game);
void useSword(entity_mob *mobs, player *user, chest * chests);
void usePotion(player * user,gameState * game, entity_mob * mobs);
void checkDano(entity_mob *mobs, player *user);
void projetil(char direcao,gameState * game);
void useTocha(gameState* game);

#endif