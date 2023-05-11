#include <rogue.h>


Entity* createPlayer(position start_pos)
{
	Entity* newPlayer = calloc(1, sizeof(Entity));

	newPlayer->pos.y = start_pos.y;
	newPlayer->pos.x = start_pos.x;
	newPlayer->ch = '@';
	newPlayer->color = COLOR_PAIR(VISIBLE_COLOR);

	return newPlayer;
}

void handleInput(int input)
{
	position newPos = { player->pos.y, player->pos.x };

	switch(input)
	{
		//move up
		case 'w':
			newPos.y--;
			break;
		//move down
		case 's':
			newPos.y++;
			break;
		//move left
		case 'a':
			newPos.x--;
			break;
		//move right
		case 'd':
			newPos.x++;
			break;
		default:
			break;
	}

	movePlayer(newPos);
}

void movePlayer(position newPos)
{
	if (dungeon[newPos.y][newPos.x].walkable)
	{
		player->pos.y = newPos.y;
		player->pos.x = newPos.x;
	}
}
