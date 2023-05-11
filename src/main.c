#include <rogue.h>

const int MAP_HEIGHT = 50;
const int	MAP_WIDTH = 150;

Entity* player;
tile** dungeon;

int main(void)
{
	position start_pos;
	bool compatibleTerminal;

	compatibleTerminal = cursesSetup();

	if (compatibleTerminal)
	{
		srand(time(NULL));

		dungeon = createDungeonTiles();
		start_pos = setupMap();
		player = createPlayer(start_pos);

		gameLoop();

		closeGame();
	}
	else
	{
		endwin();
	}

	return 0;
}
