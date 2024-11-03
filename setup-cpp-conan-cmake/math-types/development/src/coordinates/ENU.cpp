#include "coordinates/ENU.h"
#include <iostream>

ENU::ENU(double east, double north, double up) : Position3D(east, north, up) {}

void ENU::printCoordinates() const {
    std::cout << "ENU Coordinates: (" << getX() << ", " << getY() << ", " << getZ() << ")\n";
}
