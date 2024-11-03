#include "coordinates/ECEF.h"
#include <iostream>

ECEF::ECEF(double x, double y, double z) : Position3D(x, y, z) {}

void ECEF::printCoordinates() const {
    std::cout << "ECEF Coordinates: (" << getX() << ", " << getY() << ", " << getZ() << ")\n";
}
