#include "transformations/CoordinateTransform.h"
#include <cmath>

ECEF CoordinateTransform::applyRotation(const ECEF& point, double angleX, double angleY, double angleZ) {
    double newX = point.getX() * std::cos(angleY) * std::cos(angleZ);
    double newY = point.getY() * std::sin(angleX) * std::cos(angleZ);
    double newZ = point.getZ() * std::sin(angleY);
    return ECEF(newX, newY, newZ);
}

ENU CoordinateTransform::scaleENU(const ENU& enu, double scaleFactor) {
    return ENU(enu.getX() * scaleFactor, enu.getY() * scaleFactor, enu.getZ() * scaleFactor);
}
