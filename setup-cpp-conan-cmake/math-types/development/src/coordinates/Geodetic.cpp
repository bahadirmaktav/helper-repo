#include "coordinates/Geodetic.h"
#include <iostream>

Geodetic::Geodetic(double latitude, double longitude, double altitude)
    : Position3D(latitude, longitude, altitude) {}

void Geodetic::printCoordinates() const {
    std::cout << "Geodetic Coordinates: (" << getX() << ", " << getY() << ", " << getZ() << ")\n";
}
