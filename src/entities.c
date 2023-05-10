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

void add_mob_to_list(mob_node **list, tile **map) {
    if (!list) {
        return; // retorna se o ponteiro para a lista for nulo
    }
    mob_node *new_node = malloc(sizeof(mob_node));
    new_node->mob = mobsSetUp(map);
    new_node->next = *list;
    *list = new_node;
}

mob_node * createMobLList(int numMobs, tile **map) {
    mob_node *list = NULL;
    while (numMobs > 0) {
        add_mob_to_list(&list, map);
        numMobs--;
    }
    return list;
}

void freeMobNode(mob_node *node) {
    free(node->mob);
    free(node);
}

void freeMobList(mob_node *list) {
    mob_node *current = list;
    while (current != NULL) {
        mob_node *next = current->next;
        freeMobNode(current);
        current = next;
    }
}