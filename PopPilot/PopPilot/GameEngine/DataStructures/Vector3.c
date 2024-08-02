#include "Vector3.h"

void vectorAdd(const Vector3 a, const Vector3 b, Vector3 result) {
    for (int i = 0; i < 3; i++) {
        result[i] = a[i] + b[i];
    }
}

void vectorSubtract(const Vector3 a, const Vector3 b, Vector3 result) {
    for (int i = 0; i < 3; i++) {
        result[i] = a[i] - b[i];
    }
}

// Skaler �arpma
void vectorScale(const Vector3 a, float scalar, Vector3 result) {
#pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        result[i] = (float)(a[i] * scalar);
    }
}

// Skaler b�lme
void vectorDivide(const Vector3 a, float scalar, Vector3 result) {
#pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        result[i] = (float)(a[i] / scalar);
    }
}

// Nokta �arp�m�
float vectorDot(const Vector3 a, const Vector3 b) {
    float dot = 0;
    for (int i = 0; i < 3; i++) {
        dot += a[i] * b[i];
    }
    return dot;
}

// �apraz �arp�m
void vectorCross(const Vector3 a, const Vector3 b, Vector3 result) {
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

// Norm (b�y�kl�k) hesaplama
float vectorMagnitude(const Vector3 a) {
    return sqrtf(vectorDot(a, a));
}

// Normalizasyon
void vectorNormalize(const Vector3 a, Vector3 result) {
    float mag = vectorMagnitude(a);
    if (mag == 0) {
        // S�f�r vekt�r normalize edilemez
        result[0] = result[1] = result[2] = 0;
    }
    else {
        vectorDivide(a, mag, result);
    }
}

// Vekt�rler aras� mesafe hesaplama
float vectorDistance(const Vector3 a, const Vector3 b) {
    Vector3 diff;
    vectorSubtract(a, b, diff);
    return vectorMagnitude(diff);
}

// Vekt�rleri yazd�rma
void vectorPrint(const Vector3 a) {
    printf("Vector: [%f, %f, %f]\n", a[0], a[1], a[2]);
}