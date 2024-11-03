#ifndef COORDINATE_CONVERSION_H
#define COORDINATE_CONVERSION_H

#include "coordinates/ECEF.h"
#include "coordinates/ENU.h"
#include "coordinates/Geodetic.h"

class CoordinateConversion {
public:
    static ECEF GeodeticToECEF(const Geodetic& geodetic);
    static Geodetic ECEFToGeodetic(const ECEF& ecef);
    static ENU ECEFToENU(const ECEF& ecef, const Geodetic& referencePoint);
    static ECEF ENUToECEF(const ENU& enu, const Geodetic& referencePoint);
};

#endif // COORDINATE_CONVERSION_H
