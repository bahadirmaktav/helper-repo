#ifndef ECEF_H
#define ECEF_H

#include "algebra/Position3D.h"

class ECEF : public Position3D {
public:
    ECEF(double x = 0.0, double y = 0.0, double z = 0.0);

    void printCoordinates() const;
};

#endif // ECEF_H
