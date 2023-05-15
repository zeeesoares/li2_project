#include <rogue.h>

char* mobNames[] = {"Kobold", "Orc", "Goblin", "Troll", "Zombie", "Creeper", "Demon", "Slime", "Wyrm", "Bernardo"};

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
        int name = rand() % 10;
        mobArray[i].id = i;
        mobArray[i].nome = mobNames[name];
        mobArray[i].pos = start_pos;
        mobArray[i].ch = defineMobChar(name);
        mobArray[i].vida = defineMobHealth(name);
        mobArray[i].type = 0;
    }
    return mobArray;
}

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
        res = 'C';
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
        res = 'B';
        break;
    default:
        break;
    }
    return res;
}

int defineMobHealth(int name) {
    int res = 0;
    switch (name)
    {
    case 0:
        res = 120;
        break;
    case 1:
        res = 170;
        break;
    case 2:
        res = 50;
        break;
    case 3:
        res = 150;
        break;
    case 4:
        res = 90;
        break;
    case 5:
        res = 70;
        break;
    case 6:
        res = 200;
        break;
    case 7:
        res = 30;
        break;
    case 8:
        res = 170;
        break;
    case 9:
        res = 500;
        break;
    default:
        break;
    }
    return res;
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
    int numMobs = 15;
    if (map[shop->pos.y - 3][shop->pos.x -3].visible)
        shop->visible = 1;
    else shop->visible = 0;
    for (int i = 0; i < numMobs; i++) {
        if (map[(mobs+i)->pos.y - 3][(mobs+i)->pos.x -3].visible)
            (mobs+i)->visible = 1;
        else (mobs+i)->visible = 0;
    }
}



void freeMobs(entity_mob *mobs) {
    int numMobs = 15;
    for (int i = 0; i < numMobs; i++) {
            free(mobs+i);
    }
}
