#include <rogue.h>


entity_mob * mobsSetUp(tile ** map) {
    position start_pos = {rand() % 17 + 20,rand() % 17 + 20};
    entity_mob * mob;
    mob = malloc(sizeof(entity_mob));
    while (map[start_pos.y-3][start_pos.x-3].ch == '#')
        start_pos.x += 2;
    mob->pos = start_pos;
    mob->ch = 'O';
    mob->type = 0;
    return mob;
}

/*
void add_mob_to_list(mob_node **list, tile **map) {
    mob_node *new_node = malloc(sizeof(mob_node));
    new_node->mob = mobsSetUp(map);
    new_node->next = *list;
    *list = new_node;
}
*/