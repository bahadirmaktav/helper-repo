#ifndef MATRIX3X3_H
#define MATRIX3X3_H

class Matrix3x3 {
private:
    double m[3][3];

public:
    Matrix3x3();
    Matrix3x3(const double values[3][3]);

    double get(int row, int col) const;
    void set(int row, int col, double value);

    Matrix3x3 operator+(const Matrix3x3& other) const;
    Matrix3x3 operator-(const Matrix3x3& other) const;
    Matrix3x3 operator*(const Matrix3x3& other) const;

    void print() const;
};

#endif // MATRIX3X3_H
