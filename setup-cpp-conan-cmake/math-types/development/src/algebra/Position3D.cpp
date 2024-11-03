#include "algebra/Position3D.h"

Position3D::Position3D(double x, double y, double z) : x(x), y(y), z(z) {}

double Position3D::getX() const {
    return x;
}

double Position3D::getY() const {
    return y;
}

double Position3D::getZ() const {
    return z;
}

void Position3D::setX(double value) {
    x = value;
}

void Position3D::setY(double value) {
    y = value;
}

void Position3D::setZ(double value) {
    z = value;
}
