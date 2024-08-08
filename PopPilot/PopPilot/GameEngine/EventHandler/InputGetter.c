#include "InputSystem.h"
#include "../Imports.h"

#ifdef _WIN32
    #include <conio.h> 
#else
    #include <termios.h>
    #include <fcntl.h>
    #include <unistd.h>
#endif

char getkeyPressed() {
#ifdef _WIN32
    if (_kbhit())
        return _getch();
    else
        return EOF;
#else
    struct termios oldt, newt;
    int oldf;

    void init_termios(int echo) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~ICANON;
        newt.c_lflag &= echo ? ECHO : ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Non-blocking mode
    }

    void reset_termios(void) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
    }

    char ch = 0;
    init_termios(0);
    ch = getchar();
    reset_termios();
    return ch;
#endif 
}

