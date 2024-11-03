#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion {
private:
    double w, x, y, z;

public:
    Quaternion(double w = 1.0, double x = 0.0, double y = 0.0, double z = 0.0);

    double getW() const;
    double getX() const;
    double getY() const;
    double getZ() const;

    Quaternion operator+(const Quaternion& other) const;
    Quaternion operator*(const Quaternion& other) const;
    Quaternion conjugate() const;
    double norm() const;

    void print() const;
};

#endif // QUATERNION_H
