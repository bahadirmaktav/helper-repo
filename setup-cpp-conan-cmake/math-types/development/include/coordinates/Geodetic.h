#ifndef GEODETIC_H
#define GEODETIC_H

#include "algebra/Position3D.h"

class Geodetic : public Position3D {
public:
    Geodetic(double latitude = 0.0, double longitude = 0.0, double altitude = 0.0);

    void printCoordinates() const;
};

#endif // GEODETIC_H
