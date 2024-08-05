#include "InputSystem.h"
#include "../Imports.h"

#ifdef _WIN32
#include <conio.h> 
#else
#include <termios.h>
#include <unistd.h>
#endif

char getkeyPressed() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;

    void init_termios(int echo) {
        tcgetattr(STDIN_FILENO, &oldt); // get old terminal attributes
        newt = oldt; // start with old attributes
        newt.c_lflag &= ~ICANON; // disable canonical mode
        if (echo) {
            newt.c_lflag |= ECHO; // enable echo
        }
        else {
            newt.c_lflag &= ~ECHO; // disable echo
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // set new attributes
    }

    void reset_termios(void) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // reset to old terminal attributes
    }

    char ch;
    init_termios(0);
    ch = getchar();
    reset_termios();
    return ch;
#endif 
}

