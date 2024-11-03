#ifndef COORDINATE_TRANSFORM_H
#define COORDINATE_TRANSFORM_H

#include "coordinates/ECEF.h"
#include "coordinates/ENU.h"
#include "coordinates/Geodetic.h"
#include <vector>

class CoordinateTransform {
public:
    static ECEF applyRotation(const ECEF& point, double angleX, double angleY, double angleZ);
    static ENU scaleENU(const ENU& enu, double scaleFactor);
};

#endif // COORDINATE_TRANSFORM_H
