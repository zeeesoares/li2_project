#include "rogue.h"

void makeFOV(gameState * game, int raio)
{

	int y, x, distance;
    int margem = 3;
	position target;

	game->map[game->user->pos.y-margem][game->user->pos.x-margem].visible = 1;
	game->map[game->user->pos.y-margem][game->user->pos.x-margem].seen = 0;
    if (game->map[game->user->pos.y -3][game->user->pos.x -3].ch == 'i') {
        for (y = game->user->pos.y - raio; y < game->user->pos.y + raio; y++)
	        {
		    for (x = game->user->pos.x - raio; x < game->user->pos.x + raio; x++)
		    {
			    target.y = y;
			    target.x = x;
			    distance = getdistance(game->user->pos, target);

	    		if (distance < raio)
		    	{   if (isInMap(y-3,x-3) && lineOfSight(game->map, game->user->pos, target))
			    	{
			    		game->map[y-margem][x-margem].visibleT = 1;
				    	game->map[y-margem][x-margem].seen = 0;
                        game->map[y-margem][x-margem].transparent = 0;
                        game->map[y-margem][x-margem].color = VISIBLE_COLOR;
	    			}         
		    	}
    		}
	    }
    }
	
    
    for (y = game->user->pos.y - raio; y < game->user->pos.y + raio; y++)
	{
		for (x = game->user->pos.x - raio; x < game->user->pos.x + raio; x++)
		{
			target.y = y;
			target.x = x;
			distance = getdistance(game->user->pos, target);
			if (distance < raio)
			{   if (isInMap(y-3,x-3) && lineOfSight(game->map, game->user->pos, target))
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


void clearFOV(gameState * game, int raio) {
    int x, y, distance;
    int margem = 3;
    position target;

    for (y= game->user->pos.y - raio; y< game->user->pos.y + raio; y++)
        {
        for (x=game->user->pos.x -raio ; x< game->user->pos.x + raio; x++)
        {
            target.y = y;
			target.x = x;
			distance = getdistance(game->user->pos, target);
            if (distance < raio)
			{   if (isInMap(y-3,x-3) && lineOfSight(game->map, game->user->pos, target))
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

int lineOfSight(tile ** map, position origem, position alvo) {
    int delta_x = alvo.x - origem.x;
    int delta_y = alvo.y - origem.y;
    int abs_delta_x = abs(delta_x);
    int abs_delta_y = abs(delta_y);
    int sign_x = delta_x < 0 ? -1 : 1;
    int sign_y = delta_y < 0 ? -1 : 1;
    int x = origem.x;
    int y = origem.y;
    int count= 0;

    if (map[y-3][x-3].ch == '#') {
        return 0;
    }

    if (abs_delta_x > abs_delta_y) {
        int error = abs_delta_y * 2 - abs_delta_x;
        while (x != alvo.x) {
            if (error > 0) {
                y += sign_y;
                error -= abs_delta_x * 2;
            }
            x += sign_x;
            error += abs_delta_y * 2;
            if (count == 1) return 0;
            if (map[y-3][x-3].ch == '#') {
                count++;
            }
        }
    } else {
        int error = abs_delta_x * 2 - abs_delta_y;
        while (y != alvo.y) {
            if (error > 0) {
                x += sign_x;
                error -= abs_delta_y * 2;
            }
            y += sign_y;
            error += abs_delta_x * 2;
            if (count == 1) return 0;
            if (map[y-3][x-3].ch == '#') {
                count++;
            }
        }
    }
    return 1;
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

