#include "FrameController.h"
#include "../ScreenStuff/Screen.h"

int keyCodes;

int main()
{
	int i = 0;
	printf("Loading...:)");
	SystemInfo systemInfo = newSystenInfo();

	if(!functionEmpty(Awake)) {
		keyCodes = Awake(systemInfo);
		if (keyCodes == 0 || keyCodes == 1)
			exit(keyCodes);
	}

	while (true) {
		system("cls");
		if (!functionEmpty(Update)) {
			keyCodes = Update(systemInfo);
			if (keyCodes == 0 || keyCodes == 1)
				exit(keyCodes);
		}

		printScreen(*systemInfo.mainScreen);


		if (!functionEmpty(LateUpdate)) {
			keyCodes = LateUpdate(systemInfo);
			if (keyCodes == 0 || keyCodes == 1)
				exit(keyCodes);
		}
	}

}