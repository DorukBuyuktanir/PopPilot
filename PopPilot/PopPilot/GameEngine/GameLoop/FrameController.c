#include "FrameController.h"
#include "../ScreenStuff/Screen.h"
#include "../EventHandler/InputSystem.h"

int keyCodes;

int main()
{
	int i = 0;
	printf("Loading...:)");
	SystemInfo systemInfo = newSystenInfo();

	if(!functionEmpty(Awake))
		exitProgram(Awake(systemInfo), &systemInfo);

	while (true) {
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				system("cls");
				if (!functionEmpty(Update))
					exitProgram(Update(systemInfo), &systemInfo);

				printScreen(*systemInfo.mainScreen);

				if (!functionEmpty(LateUpdate))
					exitProgram(LateUpdate(systemInfo), &systemInfo);
			}

			#pragma omp section
			{
				if (getkeyPressed() == 'q')
					exitProgram(0, &systemInfo);
			}
		}
	}

}