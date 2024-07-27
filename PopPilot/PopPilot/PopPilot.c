// PopPilot.cpp: Uygulamanın giriş noktasını tanımlar.
//

#include "PopPilot.h"



int Update(SystemInfo sysInfo) {
	char pressed = getch();
	putchar(pressed);
	if (pressed == 'q')
		return 0;
	return 2;
}

int LateUpdate(SystemInfo sysInfo) {
	return 2;
}

int Awake(SystemInfo sysInfo) {
	return 2;
}
