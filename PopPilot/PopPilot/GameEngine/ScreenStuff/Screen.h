#pragma once
#include "../Components/Transform.h"
#include "../Imports.h"

// **********************Screen********************** \\

#define row 24
#define column 96

typedef uint_least32_t Screen[row][column];
Screen *newScreen(uint_least32_t insideVal);
Screen* emptyScreen();
Screen* resetScreen(Screen* screen);
void printScreen(Screen screen);

// **********************Scene********************** \\



// **********************Camera********************** \\

