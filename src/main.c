#include <rogue.h>


int main(void) {
	srandom(time(NULL));
	keypad(stdscr, true);

	player * user;
	position start_pos = {rand() % 17 + 30,rand() % 17 + 20};
	int inputs = 0;

	//ver engine.c
	ncursesSetUp();

	//ver map.c
	mapSetUp();
	drawEverything();

	//ver log.c
	logSetUp();

	//setup do "player/user"
	user = playerSetUp(start_pos);

	// ver engine.c
	gameLoop(inputs,user);

	endwin();
	free(user);

	return 0;
}
