#include "../Imports.h"
#include "Screen.h"

Layer* newLayer(uint_least32_t insideVal) {
	register Layer* lyr = (Layer*)malloc(sizeof(Layer));

	if (lyr == NULL) {
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	#pragma omp paralel for
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			(*lyr)[i][j] = insideVal;
	return lyr;
}

Layer* emptyLayer() {
	return newLayer(' ');
}

Layer* overWriteLayer(Layer baseLayer, Layer* addingLayer) {

	#pragma omp parallel for
	for (int i = 0; i < row; i++)
		#pragma omp parallel for
		for (int j = 0; j < column; j++)
			if ((*addingLayer)[i][j] != ' ' && (*addingLayer)[i][j] != '\0')
				baseLayer[i][j] = (*addingLayer)[i][j];
			else if (baseLayer[i][j] == '\0')
				baseLayer[i][j] = ' ';

	return baseLayer;
}

void printLayer(Layer* lyr) {
	register int i, j;

	#pragma omp parallel for
	for (i = 0; i < row; i++) {
		for (j = 0; j < column; j++)
			putchar((*lyr)[i][j]);
		putchar('\n');
	}
}