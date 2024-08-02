#pragma once
typedef float Vector3[3];

void vectorAdd(const Vector3 a, const Vector3 b, Vector3 result);
void vectorSubtract(const Vector3 a, const Vector3 b, Vector3 result);
void vectorScale(const Vector3 a, float scalar, Vector3 result);
void vectorDivide(const Vector3 a, float scalar, Vector3 result);
float vectorDot(const Vector3 a, const Vector3 b);
void vectorCross(const Vector3 a, const Vector3 b, Vector3 result);
float vectorMagnitude(const Vector3 a);
void vectorNormalize(const Vector3 a, Vector3 result);
float vectorDistance(const Vector3 a, const Vector3 b);
void vectorPrint(const Vector3 a);