#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
private:
    double x, y, z;

public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

    double getX() const;
    double getY() const;
    double getZ() const;

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    double dot(const Vector3D& other) const;
    Vector3D cross(const Vector3D& other) const;

    void print() const;
};

#endif // VECTOR3D_H
