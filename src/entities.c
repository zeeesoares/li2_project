#include <rogue.h>

char* mobNames[] = {"Kobold", "Orc", "Goblin", "Troll", "Zombie", "Grifo", "Demon", "Slime", "Wyrm", "DarqueMan"};

/*
- a103995 / José Soares

Função que cria array de mobs
*/

entity_mob *createMobArray(int numMobs, tile **map) {
    entity_mob *mobArray = malloc(numMobs * sizeof(entity_mob));
    if (mobArray == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return NULL;
    }
    for (int i = 0; i < numMobs; i++) {
        position start_pos = {rand() % 90 + 20, (rand() % 35) + 10};
        while (map[start_pos.y-3][start_pos.x-3].ch == '#')
            start_pos.x += 2;
        int name = rand() % 10;
        mobArray[i].id = i;
        mobArray[i].nome = mobNames[name];
        mobArray[i].pos = start_pos;
        mobArray[i].visible = 0;
        mobArray[i].visibleT = 0;
        mobArray[i].dano = defineMobDano(name);
        mobArray[i].ch = defineMobChar(name);
        mobArray[i].vida = defineMobHealth(name);
        mobArray[i].coins = defineMobCoins(name);
        mobArray[i].type = 0;
    }
    return mobArray;
}

/*
- a104446 / Nuno Melo

Funções relacionadas ao balanceamento e gestão de jogo.
*/

int defineMobDano(int name) {
    int res = 0;
    switch (name)
    {
    case 0:
        res = 15;
        break;
    case 1:
        res = 15;
        break;
    case 2:
        res = 5;
        break;
    case 3:
        res = 20;
        break;
    case 4:
        res = 7;
        break;
    case 5:
        res = 17;
        break;
    case 6:
        res = 20;
        break;
    case 7:
        res = 2;
        break;
    case 8:
        res = 17;
        break;
    case 9:
        res = 30;
        break;
    default:
        break;
    }
    return res;
}

/*
- a104446 / Nuno Melo

Funções relacionadas ao balanceamento e gestão de jogo.
*/

int defineMobCoins(int name) {
    int res = 0;
    switch (name)
    {
    case 0:
        res = 500;
        break;
    case 1:
        res = 500;
        break;
    case 2:
        res = 300;
        break;
    case 3:
        res = 900;
        break;
    case 4:
        res = 400;
        break;
    case 5:
        res = 1000;
        break;
    case 6:
        res = 1200;
        break;
    case 7:
        res = 200;
        break;
    case 8:
        res = 1000;
        break;
    case 9:
        res = 2500;
        break;
    default:
        break;
    }
    return res;
}

/*
- a104446 / Nuno Melo

Funções relacionadas ao balanceamento e gestão de jogo.
*/

char defineMobChar(int name) {
    char res = 'O';
    switch (name)
    {
    case 0:
        res = 'K';
        break;
    case 1:
        res = 'O';
        break;
    case 2:
        res = 'G';
        break;
    case 3:
        res = 'T';
        break;
    case 4:
        res = 'Z';
        break;
    case 5:
        res = 'Q';
        break;
    case 6:
        res = 'D';
        break;
    case 7:
        res = 'S';
        break;
    case 8:
        res = 'W';
        break;
    case 9:
        res = 'M';
        break;
    default:
        break;
    }
    return res;
}

/*
- a104446 / Nuno Melo

Funções relacionadas ao balanceamento e gestão de jogo.
*/

int defineMobHealth(int name) {
    int res = 0;
    switch (name)
    {
    case 0:
        res = 170;
        break;
    case 1:
        res = 170;
        break;
    case 2:
        res = 70;
        break;
    case 3:
        res = 200;
        break;
    case 4:
        res = 110;
        break;
    case 5:
        res = 200;
        break;
    case 6:
        res = 250;
        break;
    case 7:
        res = 50;
        break;
    case 8:
        res = 200;
        break;
    case 9:
        res = 600;
        break;
    default:
        break;
    }
    return res;
}

/*
- a103995 / José Soares

Função que cria array de chest
*/

chest *createChestArray(int numChests, tile **map) {
    chest *chestArray = malloc(numChests * sizeof(chest));
    if (chestArray == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return NULL;
    }
    for (int i = 0; i < numChests; i++) {
        position start_pos = {rand() % 90 + 40, (rand() % 40) + 3};
        while (map[start_pos.y-3][start_pos.x-3].ch == '#')
            start_pos.x += 2;
        chestArray[i].ch = '&';
        chestArray[i].vida = (rand() % 3 + 1) * 100;
        chestArray[i].pos = start_pos;
        chestArray[i].coins = (rand() % 3 + 1) * 500;
        chestArray[i].visible = 0;  
    }
    return chestArray;
}

/*
- a103995 / José Soares

Função que move os mobs todos da lista
*/

void moveMobs(entity_mob * mobs,tile ** map,player * user) {
    int numMobs = 30;
    for (int i = 0; i< numMobs; i++) {
        if ((mobs+i)->visibleT) {
            if ((mobs+i)->vida > 0)
                moveMob(mobs+i,map);
        }
        else if (!(mobs+i)->visible) {
            if ((mobs+i)->vida > 0)
                moveMob(mobs+i,map);
        }
        else if ((mobs+i)->vida > 0) {
            int state = rand() % 3;
            switch (state)
            {
            case 0:
                moveMobTowardsUser(mobs+i,user, map);
                break;
            case 1:
                moveMobTowardsUser(mobs+i,user, map);
                break;
            case 2:
                moveMob(mobs+i,map);
                break;
            default:
                break;
            }
        }
    }
}

/*
- a103995 / José Soares

Função que move os mobs em direção ao user
*/

void moveMobTowardsUser(entity_mob * mob, player * user, tile** map) {
    // Lista de possíveis movimentos
    position possibleMoves[] = {
        {0, -1},  // Movimento para cima
        {0, 1},   // Movimento para baixo
        {-1, 0},  // Movimento para a esquerda
        {1, 0}    // Movimento para a direita
    };

    // Posição atual do mob
    position mobPos = mob->pos;

    // Inicializa a posição de destino e a menor distância com o valor máximo
    position destination = mobPos;
    double minDistance = INFINITY;

    // Itera sobre os possíveis movimentos e encontra o movimento que leva o mob mais perto do usuário
    for (size_t i = 0; i < sizeof(possibleMoves) / sizeof(possibleMoves[0]); i++) {
        position nextPos = {mobPos.x + possibleMoves[i].x, mobPos.y + possibleMoves[i].y};

        // Verifica se a próxima posição é válida e caminhável
        if (isInMap(nextPos.y, nextPos.x) && map[nextPos.y-3][nextPos.x-3].walkable) {
            // Calcula a distância entre a próxima posição e o usuário
            double distanceToUser = getdistance(nextPos, user->pos);

            // Verifica se essa é a menor distância encontrada até agora
            if (distanceToUser < minDistance) {
                minDistance = distanceToUser;
                destination = nextPos;
            }
        }
    }

    // Move o mob para a posição de destino
    mob->pos = destination;
}

/*
- a103995 / José Soares

Função que move os mobs de forma aleatória
*/
void moveMob(entity_mob * mob, tile ** map) {

    int direcao = rand() % 10;
    switch (direcao)
    {
    case 3:
        if (isInMap(mob->pos.y + 1 -3,mob->pos.x- 3) && map[mob->pos.y + 1-3][mob->pos.x-3].walkable) {
            mob->pos.y += 1;
        }
        break;
    case 2:
        if (isInMap(mob->pos.y-3,mob->pos.x +1 -3) && map[mob->pos.y-3][mob->pos.x+1-3].walkable) {
            mob->pos.x += 1;
        }
        break;
    case 1:
        if (isInMap(mob->pos.y-3,mob->pos.x +1 -3) && map[mob->pos.y-3][mob->pos.x+1-3].walkable) {
            mob->pos.x += 1;
        }
        break;
    case 6:
        if (isInMap(mob->pos.y - 1 - 3,mob->pos.x -3)&& map[mob->pos.y -1 -3 ][mob->pos.x -3].walkable) {
            mob->pos.y -= 1;
        }
        break;
    case 9:
        if (isInMap(mob->pos.y - 3,mob->pos.x- 1 -3) && map[mob->pos.y -3][mob->pos.x-1-3].walkable) {
            mob->pos.x -= 1;
        }
        break;
    
    default:
        break;
    }
}

/*
- a103995 / José Soares

Função que conta o numero de mobs vivos no jogo.
*/
int contaMobs(entity_mob mobs[]) {
    int numMobs = 30;
    int count = 0;
    for (int i = 0; i < numMobs; i++) { // percorre o array de mobs
        if (mobs[i].vida > 0) count++;// desenha o mob atual
    }
    return count;
}


/*
- a103995 / José Soares

Função que verifica em todas as listas/entidades estão no FOV
*/
void isMobVisible (shop * shop,entity_mob * mobs, tile ** map, chest * chest) {
    int numMobs = 30;
    int numChests = 8;
    if (map[shop->pos.y - 3][shop->pos.x -3].visible || map[shop->pos.y - 3][shop->pos.x -3].visibleT)
        shop->visible = 1;
    else if (!map[shop->pos.y - 3][shop->pos.x -3].visible && !map[shop->pos.y - 3][shop->pos.x -3].visibleT)
        shop->visible = 0;
    for (int i = 0; i < numMobs; i++) {
        if (map[(mobs+i)->pos.y - 3][(mobs+i)->pos.x -3].visible)
            (mobs+i)->visible = 1;
        else if (map[(mobs+i)->pos.y - 3][(mobs+i)->pos.x -3].visibleT)
            (mobs+i)->visibleT = 1;
        else (mobs+i)->visible = 0;
    }
    for (int i = 0; i < numChests; i++) {
        if (map[(chest+i)->pos.y - 3][(chest+i)->pos.x -3].visible || map[(chest+i)->pos.y - 3][(chest+i)->pos.x -3].visibleT)
            (chest+i)->visible = 1;
        else (chest+i)->visible = 0;
    }
}
