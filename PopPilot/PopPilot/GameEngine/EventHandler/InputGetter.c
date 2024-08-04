#include "InputSystem.h"
#include "../Imports.h"

#ifdef _WIN32
#include <conio.h> 

char getkeyPressed() {
    return _getch();
}
#else
#include <termios.h>

// Terminal settings for Unix-based systems
struct termios oldt, newt;

void init_termios(int echo) {
    tcgetattr(0, &oldt); // get old terminal attributes
    newt = oldt; // start with old attributes
    newt.c_lflag &= ~ICANON; // disable canonical mode
    if (echo) {
        newt.c_lflag |= ECHO; // enable echo
    }
    else {
        newt.c_lflag &= ~ECHO; // disable echo
    }
    tcsetattr(0, TCSANOW, &newt); // set new attributes
}

void reset_termios(void) {
    tcsetattr(0, TCSANOW, &oldt); // reset to old terminal attributes
}
char getkeyPressed() {
    char ch;
    init_termios(0);
    ch = getchar();
    reset_termios();
    return ch;
}
#endif


