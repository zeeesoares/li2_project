#include <rogue.h>
#include <ncurses.h>

int ncursesSetUp() {
	initscr();
	curs_set(0);
	start_color;
	init_pair (1,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printw("Hello World!");
	attroff(COLOR_PAIR(1));
	noecho();
	refresh();

}

int main(void) {	
	player * user;
	position start_pos = {9,9};
	int exits;

	ncursesSetUp();
	mapSetUp();
	logSetUp();

	user = playerSetUp(start_pos);

	// MAIN GAME LOOP
	while ((exits = getch()) != 'q') {
		handleInput(exits,user);
	}
	endwin();
	return 0;
}
