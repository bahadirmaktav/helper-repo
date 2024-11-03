#include "calculations/AngleCalculator.h"
#include <cmath>

double AngleCalculator::calculateAzimuth(const ECEF& point1, const ECEF& point2) {
    double dx = point2.getX() - point1.getX();
    double dy = point2.getY() - point1.getY();
    return std::atan2(dy, dx) * 180 / M_PI;
}
