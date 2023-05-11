#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// color pairs
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2

typedef struct position
{
	int y;
	int x;
} position;

typedef struct tile
{
	char ch;
	int color;
	bool walkable;
	bool transparent;
	bool visible;
	bool seen;
} tile;

typedef struct
{
	int height;
	int width;
	position pos;
	position center;
} Room;

typedef struct
{
	position pos;
	char ch;
	int color;
} Entity;

typedef struct menu
{
	int jogar;
	int sair;
} menu;


typedef struct gameState
{
	menu modo;
	Entity* user;
	tile ** map;
} gameState;

typedef struct portal
{
	int dimensao;
} portal;


//draw.c functions
void drawDungeon(void);
void drawEntity(Entity* entity);
void drawEveryDungeon(void);

//engine.c functions
bool cursesSetup(void);
void gameLoop(void);
void closeGame(void);

//map.c functions
tile** createDungeonTiles(void);
position setupMap(void);
void freeMap(void);

// player.c functions
Entity* createPlayer(position start_pos);
void handleInput(int input);
void movePlayer(position newPos);

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(position centerOne, position centerTwo);

// fov.c functions
void makeFOV(Entity* player);
void clearFOV(Entity* player);
int getDistance(position origin, position target);
bool isInMap(int y, int x);
bool lineOfSight(position origin, position target);
int getSign(int a);

// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity* player;
extern tile** dungeon;

#endif
