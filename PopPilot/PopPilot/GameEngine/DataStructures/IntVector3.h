#pragma onces
typedef int IntVector3[3];

void intVectorAdd(const IntVector3 a, const IntVector3 b, IntVector3 result);
void intVectorSubtract(const IntVector3 a, const IntVector3 b, IntVector3 result);
void intVectorScale(const IntVector3 a, float scalar, IntVector3 result);
void intVectorDivide(const IntVector3 a, float scalar, IntVector3 result);
float intVectorDot(const IntVector3 a, const IntVector3 b);
void intVectorCross(const IntVector3 a, const IntVector3 b, IntVector3 result);
float intVectorMagnitude(const IntVector3 a);
void intVectorNormalize(const IntVector3 a, IntVector3 result);
float intVectorDistance(const IntVector3 a, const IntVector3 b);
void intVectorPrint(const IntVector3 a);