#include "IntVector3.h"

void intVectorAdd(const IntVector3 a, const IntVector3 b, IntVector3 result) {
    for (int i = 0; i < 3; i++) {
        result[i] = a[i] + b[i];
    }
}

void intVectorSubtract(const IntVector3 a, const IntVector3 b, IntVector3 result) {
    for (int i = 0; i < 3; i++) {
        result[i] = a[i] - b[i];
    }
}

// Skaler çarpma
void intVectorScale(const IntVector3 a, float scalar, IntVector3 result) {
#pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        result[i] = (int)(a[i] * scalar);
    }
}

// Skaler bölme
void intVectorDivide(const IntVector3 a, float scalar, IntVector3 result) {
#pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        result[i] = (int)(a[i] / scalar);
    }
}

// Nokta çarpýmý
float intVectorDot(const IntVector3 a, const IntVector3 b) {
    float dot = 0;
    for (int i = 0; i < 3; i++) {
        dot += a[i] * b[i];
    }
    return dot;
}

// Çapraz çarpým
void intVectorCross(const IntVector3 a, const IntVector3 b, IntVector3 result) {
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

// Norm (büyüklük) hesaplama
float intVectorMagnitude(const IntVector3 a) {
    return sqrtf(vectorDot(a, a));
}

// Normalizasyon
void intVectorNormalize(const IntVector3 a, IntVector3 result) {
    float mag = vectorMagnitude(a);
    if (mag == 0) {
        // Sýfýr vektör normalize edilemez
        result[0] = result[1] = result[2] = 0;
    }
    else {
        vectorDivide(a, mag, result);
    }
}

// Vektörler arasý mesafe hesaplama
float intVectorDistance(const IntVector3 a, const IntVector3 b) {
    IntVector3 diff;
    vectorSubtract(a, b, diff);
    return vectorMagnitude(diff);
}

// Vektörleri yazdýrma
void intVectorPrint(const IntVector3 a) {
    printf("Vector: [%d, %d, %d]\n", a[0], a[1], a[2]);
}