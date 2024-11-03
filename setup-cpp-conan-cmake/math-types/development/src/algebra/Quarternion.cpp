#include "algebra/Quaternion.h"
#include <iostream>
#include <cmath>

Quaternion::Quaternion(double w, double x, double y, double z) 
    : w(w), x(x), y(y), z(z) {}

double Quaternion::getW() const {
    return w;
}

double Quaternion::getX() const {
    return x;
}

double Quaternion::getY() const {
    return y;
}

double Quaternion::getZ() const {
    return z;
}

Quaternion Quaternion::operator+(const Quaternion& other) const {
    return Quaternion(w + other.getW(), x + other.getX(), y + other.getY(), z + other.getZ());
}

Quaternion Quaternion::operator*(const Quaternion& other) const {
    return Quaternion(
        w * other.getW() - x * other.getX() - y * other.getY() - z * other.getZ(),
        w * other.getX() + x * other.getW() + y * other.getZ() - z * other.getY(),
        w * other.getY() - x * other.getZ() + y * other.getW() + z * other.getX(),
        w * other.getZ() + x * other.getY() - y * other.getX() + z * other.getW()
    );
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(w, -x, -y, -z);
}

double Quaternion::norm() const {
    return std::sqrt(w * w + x * x + y * y + z * z);
}

void Quaternion::print() const {
    std::cout << "Quaternion: (" << w << ", " << x << ", " << y << ", " << z << ")\n";
}
