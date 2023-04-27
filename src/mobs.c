#include <rogue.h>

entity_mob * mobsSetUp(position start_pos) {
    entity_mob * mob;
    mob = malloc(sizeof(entity_mob));

    mob->pos = start_pos;
    mob->ch = 'O';
    mob->type = 0;
    return mob;
}

