#include <rogue.h>


int main(void) {	
	player * user;
	position start_pos = {9,9};
	int inputs = 0;

	//ver engine.c
	ncursesSetUp();

	//ver map.c
	mapSetUp();

	//ver log.c
	logSetUp();

	//setup do "player/user"
	user = playerSetUp(start_pos);

	// ver engine.c
	gameLoop(inputs,user);

	endwin();
	return 0;
}
