#include <rogue.h>

Room createRoom(int y, int x, int height, int width)
{
	Room newRoom;

	newRoom.pos.y = y;
	newRoom.pos.x = x;
	newRoom.height = height;
	newRoom.width = width;
	newRoom.center.y = y + (int)(height / 2);
	newRoom.center.x = x + (int)(width / 2);

	return newRoom;
}

void addRoomToMap(Room room)
{
	for (int y = room.pos.y; y < room.pos.y + room.height; y++)
	{
		for (int x = room.pos.x; x < room.pos.x + room.width; x++)
		{
			dungeon[y][x].ch = '.';
			dungeon[y][x].walkable = true;
			dungeon[y][x].transparent = true;
		}
	}
}

void connectRoomCenters(position centerOne, position centerTwo)
{
	position temp;
	temp.x = centerOne.x;
	temp.y = centerOne.y;

	while (true)
	{
		if (abs((temp.x - 1) - centerTwo.x) < abs(temp.x - centerTwo.x))
			temp.x--;
		else if (abs((temp.x + 1) - centerTwo.x) < abs(temp.x - centerTwo.x))
			temp.x++;
		else if (abs((temp.y + 1) - centerTwo.y) < abs(temp.y - centerTwo.y))
			temp.y++;
		else if (abs((temp.y - 1) - centerTwo.y) < abs(temp.y - centerTwo.y))
			temp.y--;
		else
			break;

		dungeon[temp.y][temp.x].ch = '.';
		dungeon[temp.y][temp.x].walkable = true;
		dungeon[temp.y][temp.x].transparent = true;
	}
}

