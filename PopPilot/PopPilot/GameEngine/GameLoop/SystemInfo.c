#include "SystemInfo.h"
#include "../ScreenStuff/Screen.h"


SystemInfo newSystenInfo() {
	SystemInfo* systemInfoPtr = (SystemInfo*)malloc(sizeof(SystemInfo));

	if (systemInfoPtr == NULL) {
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	systemInfoPtr->mainScreen = emptyScreen();
	systemInfoPtr->areWeChilling = true;
	return *systemInfoPtr;
}

void exitProgram(int key, SystemInfo* systemInfo) {
	if (key == 0 || key == 1)
		systemInfo->areWeChilling = false;
}