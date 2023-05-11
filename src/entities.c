#include <rogue.h>


entity_mob * mobsSetUp(tile ** map) {
    position start_pos = {rand() % 90 + 20, (rand() % 35) + 10};
    entity_mob * mob;
    mob = malloc(sizeof(entity_mob));
    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    mob->pos = start_pos;
    mob->ch = 'O';
    mob->vida = 100;
    mob->type = 0;
    return mob;
}

entity_mob *createMobArray(int numMobs, tile **map) {
    entity_mob *mobArray = malloc(numMobs * sizeof(entity_mob));
    if (mobArray == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        return NULL;
    }
    for (int i = 0; i < numMobs; i++) {
        position start_pos = {rand() % 90 + 20, (rand() % 35) + 10};
        while (map[start_pos.y-3][start_pos.x-3].ch == '#')
            start_pos.x += 2;
        mobArray[i].pos = start_pos;
        mobArray[i].ch = 'O';
        mobArray[i].vida = 100;
        mobArray[i].type = 0;
    }
    return mobArray;
}


void freeMobs(entity_mob * mobs) {
    for (int i = 0; i < 11; i++) {
        free(mobs);
    }
}