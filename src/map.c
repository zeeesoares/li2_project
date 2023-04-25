#include <rogue.h>

int mapSetUp() {
    int rows = 40;
    int cols = 135;

    // alocar memória para o array bidimensional
    char **map = (char **) malloc(rows * sizeof(char *));
    for(int i = 0; i < rows; i++) {
        map[i] = (char *) malloc(cols * sizeof(char));
    }

    // preencher o array bidimensional com caracteres aleatórios
    int limit = RAND_MAX / 2;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int r = rand();
            if(r < limit) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }

    // imprimir o mapa
    initscr();
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            mvprintw(i+5, j+5, "%c", map[i][j]);
        }
    }
}
