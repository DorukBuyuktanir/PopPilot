#include "SystemInfo.h"
#include "../ScreenStuff/Screen.h"

SystemInfo newSystenInfo() {
	SystemInfo* systemInfoPtr = (SystemInfo*)malloc(sizeof(SystemInfo));

	if (systemInfoPtr == NULL) {
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	systemInfoPtr->mainScreen = emptyScreen();
	return *systemInfoPtr;
}