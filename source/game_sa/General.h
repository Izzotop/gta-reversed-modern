/*
    Plugin-SDK file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include <cstdlib> // RAND_MAX

class CGeneral {
public:
    static void InjectHooks();

    static float LimitAngle(float angle);
    static float LimitRadianAngle(float angle);
    static float GetRadianAngleBetweenPoints(float x1, float y1, float x2, float y2);
    static float GetATanOfXY(float x, float y);
    static float GetATanOf(CVector2D point) { return GetATanOfXY(point.x, point.y); }
    static uint32 GetNodeHeadingFromVector(float x, float y);
    static bool SolveQuadratic(float a, float b, float c, float& x1, float& x2);
    static float GetAngleBetweenPoints(float x1, float y1, float x2, float y2);
    static uint16 GetRandomNumber();
    static int32 GetRandomNumberInRange(const int32 min, const int32 max);
    static float GetRandomNumberInRange(const float min, const float max);

    // NOTSA - Helpers
    static float GetRadianAngleBetweenPoints(CVector2D a, CVector2D b);
    static bool DoCoinFlip();
};

constexpr float RAND_MAX_INT_RECIPROCAL = 1.0f / static_cast<float>(RAND_MAX + 1); // 1.0 / 32768.0 == 1.0 / (RAND_MAX + 1) = 0.0000305175781
constexpr float RAND_MAX_FLOAT_RECIPROCAL = 1.0f / static_cast<float>(RAND_MAX);   // 1.0 / 32767.0 == 1.0 / RAND_MAX       = 0.0000305185094
