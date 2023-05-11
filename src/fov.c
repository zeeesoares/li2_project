#include "rogue.h"
void makeFOV(gameState * game)
{
	int y, x, distance;
	int raio = 15;
    int margem = 3;
	position target;

	game->map[game->user->pos.y-margem][game->user->pos.x-margem].visible = 1;
	game->map[game->user->pos.y-margem][game->user->pos.x-margem].seen = 0;

	for (y = game->user->pos.y - raio; y < game->user->pos.y + raio; y++)
	{
		for (x = game->user->pos.x - raio; x < game->user->pos.x + raio; x++)
		{
			target.y = y;
			target.x = x;
			distance = getdistance(game->user->pos, target);

			if (distance < raio)
			{   if (isInMap(y-3,x-3))
				{
					game->map[y-margem][x-margem].visible = 1;
					game->map[y-margem][x-margem].seen = 0;
                    game->map[y-margem][x-margem].transparent = 0;
                    game->map[y-margem][x-margem].color = VISIBLE_COLOR;
				}         
			}
		}
	}
}


void clearFOV(gameState * game) {
    int x, y, distance;
    int margem = 3;
    int raio = 15;
    position target;

    for (y= game->user->pos.y - raio; y< game->user->pos.y + raio; y++)
        {
        for (x=game->user->pos.x -raio; x< game->user->pos.x + raio; x++)
        {
            target.y = y;
			target.x = x;
			distance = getdistance(game->user->pos, target);
            if (distance < raio)
			{   if (isInMap(y-3,x-3))
			    {
                    game->map[y-margem][x-margem].visible = 0;
                    game->map[y-margem][x-margem].seen = 1;
                    game->map[y-margem][x-margem].transparent = 0;
                    game->map[y-margem][x-margem].color = COLOR_PAIR(SEEN_COLOR);
			    }         
			}
        }
    }
}

int getdistance (position origem, position alvo) {
    double dx;
    double dy;
    int distance;
    dx = alvo.x - origem.x;
    dy = alvo.y - origem.y;
    distance = floor(sqrt((dx * dx) + (dy * dy)));
    return distance;
}

int isInMap(int y, int x) {
    if (( 0 <= y && y < 55) && (0 <= x && x <= 150)){
        return 1;
    }
    return 0;
}
<<<<<<< HEAD

*/
=======
>>>>>>> origin/main
