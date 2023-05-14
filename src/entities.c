#include <rogue.h>

char* mobNames[] = {"Kobold", "Orc", "Goblin", "Troll", "Zombie", "Skeleton", "Demon", "Slime", "Wyrm", "Dragon"};

entity_mob * mobsSetUp(tile ** map) {
    position start_pos = {rand() % 90 + 20, (rand() % 35) + 10};
    entity_mob * mob;
    mob = malloc(sizeof(entity_mob));
    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    mob->pos = start_pos;
    mob->ch = 'O';
    mob->visible = 0;
    mob->vida = 100;
    mob->type = 0;
    return mob;
}

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
        mobArray[i].id = i;
        mobArray[i].nome = mobNames[rand() % 10];
        mobArray[i].pos = start_pos;
        mobArray[i].ch = 'O';
        mobArray[i].vida = 100;
        mobArray[i].type = 0;
    }
    return mobArray;
}
/*
void* moveMobThread(void* arg) {
    gameState * game = (gameState*) arg;

    while (1) {
        for (int i = 0; i < 10; i++) {
            moveMob(game->mobs + i, game->map);
        }
        usleep(500000);
    }

    return NULL;
}

// Função para iniciar as threads que movem os monstros
void startMonsterThreads(gameState * game) {
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, moveMobThread, game);
    }
}

void moveMob(entity_mob * mob, tile ** map) {

    int direcao = rand() % 4;
    switch (direcao)
    {
    case 0:
        if (isInMap(mob->pos.y + 1 -3,mob->pos.x- 3) && map[mob->pos.y + 1-3][mob->pos.x-3].ch == '.') {
            mob->pos.y += 1;
        }
        break;
    case 1:
        if (isInMap(mob->pos.y-3,mob->pos.x +1 -3)&& map[mob->pos.y-3][mob->pos.x+1-3].ch == '.') {
            mob->pos.x += 1;
        }
        break;
    case 2:
        if (isInMap(mob->pos.y - 1 - 3,mob->pos.x -3)&& map[mob->pos.y -1 -3 ][mob->pos.x -3].ch == '.') {
            mob->pos.y -= 1;
        }
        break;
    case 3:
        if (isInMap(mob->pos.y - 3,mob->pos.x- 1 -3) && map[mob->pos.y -3][mob->pos.x-1-3].ch == '.') {
            mob->pos.y -= 1;
        }
        break;
    
    default:
        break;
    }
}
*/

void isMobVisible (shop * shop,entity_mob * mobs, tile ** map) {
    if (map[shop->pos.y - 3][shop->pos.x -3].visible)
        shop->visible = 1;
    else shop->visible = 0;
    for (int i = 0; i < 10; i++) {
        if (map[(mobs+i)->pos.y - 3][(mobs+i)->pos.x -3].visible)
            (mobs+i)->visible = 1;
        else (mobs+i)->visible = 0;
    }
}



void freeMobs(entity_mob *mobs) {
    for (int i = 0; i < 10; i++) {
            free(mobs+i);
    }
}
