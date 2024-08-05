#pragma once

#include "../Imports.h"
#include "../ScreenStuff/Screen.h"


typedef struct {
	Screen* mainScreen;
}SystemInfo;

SystemInfo newSystenInfo();
void exitProgram(int key, SystemInfo* systemInfo);