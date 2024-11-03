#ifndef POSITION3D_H
#define POSITION3D_H

class Position3D {
protected:
    double x, y, z;

public:
    Position3D(double x = 0.0, double y = 0.0, double z = 0.0);
    virtual ~Position3D() = default;

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double value);
    void setY(double value);
    void setZ(double value);
};

#endif // POSITION3D_H
