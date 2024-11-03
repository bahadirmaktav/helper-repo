#include "conversions/CoordinateConversion.h"
#include <cmath>

ECEF CoordinateConversion::GeodeticToECEF(const Geodetic& geodetic) {
    double x = geodetic.getX() * 1000.0;
    double y = geodetic.getY() * 1000.0;
    double z = geodetic.getZ();
    return ECEF(x, y, z);
}

Geodetic CoordinateConversion::ECEFToGeodetic(const ECEF& ecef) {
    double latitude = ecef.getX() / 1000.0;
    double longitude = ecef.getY() / 1000.0;
    double altitude = ecef.getZ();
    return Geodetic(latitude, longitude, altitude);
}

ENU CoordinateConversion::ECEFToENU(const ECEF& ecef, const Geodetic& referencePoint) {
    double east = ecef.getX() - referencePoint.getX() * 1000.0;
    double north = ecef.getY() - referencePoint.getY() * 1000.0;
    double up = ecef.getZ() - referencePoint.getZ();
    return ENU(east, north, up);
}

ECEF CoordinateConversion::ENUToECEF(const ENU& enu, const Geodetic& referencePoint) {
    double x = enu.getX() + referencePoint.getX() * 1000.0;
    double y = enu.getY() + referencePoint.getY() * 1000.0;
    double z = enu.getZ() + referencePoint.getZ();
    return ECEF(x, y, z);
}
