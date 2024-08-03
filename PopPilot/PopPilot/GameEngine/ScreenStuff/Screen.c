#include "Screen.h"

Screen *newScreen(uint_least32_t insideVal) {
	Screen* scrnPtr = (Screen*)malloc(sizeof(Screen));
	if (scrnPtr == NULL) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	#pragma omp parallel for
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			(*scrnPtr)[i][j] = insideVal;
		}
	}

	return scrnPtr;
}

Screen* emptyScreen() {
	return newScreen((uint_least32_t)' ');
}

Screen* resetScreen(Screen* screen) {
	#pragma omp parallel for
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			(*screen)[i][j] = ' ';
}

void printScreen(Screen screen) {
	#pragma omp parallel for
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				printf("%lc", screen[i][j]);
			}
			putchar('\n');
		}

}