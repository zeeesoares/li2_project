#include "rogue.h"

void makeFOV(player* user){
    int x;
    int y;
    int distancia;
    int raio = 9;
    position alvo;

    map[user->pos.y][user->pos.x].visible = true;
    map[user->pos.y][user->pos.x].seen = true;

    for (y= user->pos.y - raio; y< user->pos.y; y++){
        for (x=user->pos.x -raio; x< user->pos.x;x++){
            alvo.y = y;
            alvo.x = x;
            distancia = getdistance(user->pos, alvo);

            if (distancia < raio){
                if (isInMap(y,x) && lineOfSight(user->pos,alvo)){
                    map[y][x].visible = true;
                    map[y][x].seen = true;
                }
            }
        }
    }
}

void clearFOV(player* user){
    int x;
    int y;
    int raio = 9;

    for (y= user->pos.y - raio; y< user->pos.y; y++){
        for (x=user->pos.x -raio; x< user->pos.x; x++){
            if (isInMap(y,x)){
                map[y][x].visible = false;
            }
        }
    }

int getdistance (position origem, position alvo){
    double dx;
    double dy;
    int distance;
    dx = alvo.x - origem.x;
    dy = alvo.y - origem.y;
    distance = floor(sqrt((dx * dx) + (dy * dy));
    return distance;
}

bool isInMap(int y, int x){
    if (( 0 < x && x < 39) && (0 < y && y < 134)){
        return true;
    }
    return false; 


bool lineOfSight(position origem, position alvo){
    int t;
    int x;
    int y;
    int abs_delta_x;
    int abs_delta_y;
    int sign_x;
    int sign_y;
    int delta_x;
    int delta_y;

    delta_x= origem.x - alvo.x;
    delta_y = origem.y - alvo.x;

    sign_x = getSign(delta_x);
    sign_y = getSign(delta_y);

    x = alvo.x;
    y = alvo.y;

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

            if (x== origem.x && y== origem.y){
                return true;
            }

        }
        while (map[y][x].transparent);
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

            if (x== origem.x && y== origem.y){
                return true;
            }

        }
        while (map[y][x].transparent);
        return false;
    }
}

int getSign(int a){
    return (a < 0) ? -1:1; 
}
