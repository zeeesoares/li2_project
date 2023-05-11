#include <rogue.h>

void drawDungeon(void)
{
	for (int y = 5; y < MAP_HEIGHT; y++)
	{
		for (int x = 5; x < MAP_WIDTH; x++)
		{
			if (dungeon[y][x].visible)
			{
				mvaddch(y, x, dungeon[y][x].ch | dungeon[y][x].color);
			}
			else if (dungeon[y][x].seen)
			{
				mvaddch(y, x, dungeon[y][x].ch | COLOR_PAIR(SEEN_COLOR));
			}
			else
			{
				mvaddch(y, x, ' ');
			}
		}
	}
}

void drawEntity(Entity* entity)
{
	mvaddch(entity->pos.y, entity->pos.x, entity->ch | entity->color);
}

void drawEveryDungeon(void)
{
	clear();
	drawDungeon();
	drawEntity(player);
}
