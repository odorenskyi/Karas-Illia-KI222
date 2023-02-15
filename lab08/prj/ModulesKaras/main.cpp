#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>


float s_calculation(float x, float y, float z)
{
    float S;
    const double pi = 3.14159265358979323846;
    S=log(x) * sin(z) + (1.0 / 2.0 * pow(x, 2) - pow(sqrt(y + z), 2) - pow(x, 5)) / (10.0 * pi * pow(z, 4));
    return roundf(S * 100000.0f) / 100000.0f;
}
