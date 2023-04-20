#include <rogue.h>

int ncursesSetUp() {
	initscr();
	curs_set(0);
	printw("Hello World!");
	noecho();
	refresh();

}

int main(void) {	
	ncursesSetUp();
	mapSetUp();
	drawPlayer();
	while (getch() != 'q');
	endwin();
	return 0;
}
