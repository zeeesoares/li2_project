#include <rogue.h>

void cursesSetup(void)
{ 
  initscr();
  noecho();
  curs_set(0);
}

void gameLoops()
{ 
  int ch=0;
  drawEverything();


  while(ch == getch())
  { 
    if (ch == 'q')
    { 
      break;
    } 

    handleInput(ch);
    drawEverything();

  } 
} 

void closeGames()
{ 
  endwin();
  free(jogador);
} 
