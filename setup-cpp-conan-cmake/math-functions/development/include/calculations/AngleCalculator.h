#ifndef ANGLE_CALCULATOR_H
#define ANGLE_CALCULATOR_H

#include "coordinates/ECEF.h"

class AngleCalculator {
public:
    static double calculateAzimuth(const ECEF& point1, const ECEF& point2);
};

#endif // ANGLE_CALCULATOR_H
