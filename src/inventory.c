#include <rogue.h>

void handleInventory(int input) {
    keypad(stdscr, true);
    int count = 1;
    switch (input)
    {
    case '1':
        invLog(1,count);
        break;
    case '2':
        invLog(2,count);
        break;
    case '3':
        invLog(3,count);
        break;
    default:
        break;
    }
}