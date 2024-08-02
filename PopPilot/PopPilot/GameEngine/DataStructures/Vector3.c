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

// Skaler çarpma
void vectorScale(const Vector3 a, float scalar, Vector3 result) {
#pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        result[i] = (float)(a[i] * scalar);
    }
}

// Skaler bölme
void vectorDivide(const Vector3 a, float scalar, Vector3 result) {
#pragma omp parallel for
    for (int i = 0; i < 3; i++) {
        result[i] = (float)(a[i] / scalar);
    }
}

// Nokta çarpýmý
float vectorDot(const Vector3 a, const Vector3 b) {
    float dot = 0;
    for (int i = 0; i < 3; i++) {
        dot += a[i] * b[i];
    }
    return dot;
}

// Çapraz çarpým
void vectorCross(const Vector3 a, const Vector3 b, Vector3 result) {
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

// Norm (büyüklük) hesaplama
float vectorMagnitude(const Vector3 a) {
    return sqrtf(vectorDot(a, a));
}

// Normalizasyon
void vectorNormalize(const Vector3 a, Vector3 result) {
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
float vectorDistance(const Vector3 a, const Vector3 b) {
    Vector3 diff;
    vectorSubtract(a, b, diff);
    return vectorMagnitude(diff);
}

// Vektörleri yazdýrma
void vectorPrint(const Vector3 a) {
    printf("Vector: [%f, %f, %f]\n", a[0], a[1], a[2]);
}