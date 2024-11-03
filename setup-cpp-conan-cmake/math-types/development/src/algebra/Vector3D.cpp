#include "algebra/Vector3D.h"
#include <iostream>

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3D::getX() const {
    return x;
}

double Vector3D::getY() const {
    return y;
}

double Vector3D::getZ() const {
    return z;
}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(x + other.getX(), y + other.getY(), z + other.getZ());
}

Vector3D Vector3D::operator-(const Vector3D& other) const {
    return Vector3D(x - other.getX(), y - other.getY(), z - other.getZ());
}

double Vector3D::dot(const Vector3D& other) const {
    return x * other.getX() + y * other.getY() + z * other.getZ();
}

Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D(
        y * other.getZ() - z * other.getY(),
        z * other.getX() - x * other.getZ(),
        x * other.getY() - y * other.getX()
    );
}

void Vector3D::print() const {
    std::cout << "Vector3D: (" << x << ", " << y << ", " << z << ")\n";
}
