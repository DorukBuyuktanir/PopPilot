#include "../Imports.h"
#include "Screen.h"

Screen newScreen(uint_least32_t value) {
	Screen* scrn = (Screen*)malloc(sizeof(Screen));

	if (scrn == NULL) {
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	return *scrn;
}

Screen emptyScreen() {
	return newScreen(' ');
}

Screen resetScreen(Screen* scrn) {
	(*scrn) = emptyScreen();

	return *scrn;
}

void printScreen(Screen scrn) {
	Layer* lyr = combineLayers(scrn);
	printLayer(lyr);
}

void deleteScreen(Screen* scrn) {
	free(*(scrn->layer0));
	free(*(scrn->layer1));
	free(*(scrn->layer2));
	free(scrn);
}