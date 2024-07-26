#include "../Imports.h"
#include "Screen.h"

Screen* newScreen(uint_least32_t value) {
	register Screen* scrn = (Screen*)malloc(sizeof(Screen));

	if (scrn == NULL) {
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	scrn->layer0 = *newLayer(value);
	scrn->layer1 = *newLayer(value);
	scrn->layer2 = *newLayer(value);
	scrn->UIlayer = *emptyLayer();
	return scrn;
}

Screen* emptyScreen() {
	return newScreen(' ');
}

Layer* combineLayers(Screen* scrn) {
	register Layer* lyr = overWriteLayer(scrn->layer0, scrn->layer1);
	lyr = overWriteLayer(lyr, scrn->layer2);
	lyr = overWritelayer(lyr, scrn->UIlayer);
	return lyr;
}