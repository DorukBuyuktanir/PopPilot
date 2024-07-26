#pragma once
#include <stdint.h>

// **********************Layer********************** \\

#define row 24
#define column 96

typedef uint_least32_t Layer[row][column];

Layer* newLayer(uint_least32_t insideVal);
Layer* emptyLayer();
Layer* overWriteLayer(Layer baseLayer, Layer* addingLayer);

void printLayer(Layer* lyr);

// **********************Screen********************** \\

typedef struct Screen {
	Layer layer0;
	Layer layer1;
	Layer layer2;
	Layer UIlayer;
}Screen;

Screen newScreen(uint_least32_t value);
Screen emptyScreen();
Screen resetScreen(Screen* scrn);

Layer* combineLayers(Screen scrn);

void printScreen(Screen scrn);
void deleteScreen(Screen* scrn);

