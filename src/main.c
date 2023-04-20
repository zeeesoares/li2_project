#include <rogue.h>

int ncursesSetUp() {
	initscr();
	curs_set(0);
	printw("Hello World!");
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
