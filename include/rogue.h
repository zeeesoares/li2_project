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

typedef struct
{
	char ch;
	int color;
	bool walkable;
	bool transparent;
	bool visible;
	bool seen;
} Tile;

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


typedef struct gameState
{
	Entity* user;
	char ** map;
} gameState;


//draw.c functions
void drawDungeon(void);
void drawEntity(Entity* entity);
void drawEveryDungeon(void);

//engine.c functions
bool cursesSetup(void);
void gameLoop(void);
void closeGame(void);

//map.c functions
Tile** createMapTiles(void);
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


// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity* player;
extern Tile** dungeon;

#endif
