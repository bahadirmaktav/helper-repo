#ifndef ENU_H
#define ENU_H

#include "algebra/Position3D.h"

class ENU : public Position3D {
public:
    ENU(double east = 0.0, double north = 0.0, double up = 0.0);

    void printCoordinates() const;
};

#endif // ENU_H
