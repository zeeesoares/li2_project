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
	logSetUp();
	while (getch() != 'q');
	endwin();
	return 0;
}
