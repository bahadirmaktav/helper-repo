#include "calculations/DistanceCalculator.h"

double DistanceCalculator::calculateDistance(const ECEF& point1, const ECEF& point2) {
    double dx = point2.getX() - point1.getX();
    double dy = point2.getY() - point1.getY();
    double dz = point2.getZ() - point1.getZ();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}
