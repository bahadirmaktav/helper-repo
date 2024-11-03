#ifndef DISTANCE_CALCULATOR_H
#define DISTANCE_CALCULATOR_H

#include "coordinates/ECEF.h"
#include <cmath>

class DistanceCalculator {
public:
    static double calculateDistance(const ECEF& point1, const ECEF& point2);
};

#endif // DISTANCE_CALCULATOR_H
