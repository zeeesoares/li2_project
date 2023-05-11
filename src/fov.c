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
			{   if (isInMap(y-3,x-3) && lineofsight(target,game))
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

int lineofsight(position target,gameState *game){
    int t;
    int x;
    int y;
    int abs_delta_x;
    int abs_delta_y;
    int sign_x;
    int sign_y;
    int delta_x;
    int delta_y;

    delta_x= game->user->pos.x - target.x;
    delta_y = game->user->pos.y - target.x;

    sign_x = getSign(delta_x);
    sign_y = getSign(delta_y);

    abs_delta_x= abs(delta_x);
    abs_delta_y = abs(delta_y);

    x = target.x;
    y = target.y;

    if (abs_delta_x > abs_delta_y){
        t = abs_delta_y * 2 - abs_delta_x;

        do{
            if (t>=0)
            {
                y+= sign_y;
                t-= abs_delta_x * 2;
            }
            x+= sign_x;
            t+= abs_delta_y *2;

            if (x== game->user->pos.x && y== game->user->pos.y){
                return true;
            }

        }
        while (game->map[y][x].transparent);
        return false;
    }
    else
    {
        t = abs_delta_x * 2 - abs_delta_y;

        do{
            if (t>=0)
            {
                x+= sign_x;
                t-= abs_delta_y * 2;
            }
            y+= sign_y;
            t+= abs_delta_x *2;

            if (x== game->user->pos.x && y== game->user->pos.y){
                return true;
            }

        }
        while (game->map[y][x].transparent);
        return false;
    }
}

int getSign(int a){
    return (a < 0) ? -1:1;
}
