#include "algebra/Matrix3x3.h"
#include <iostream>

Matrix3x3::Matrix3x3() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m[i][j] = 0.0;
        }
    }
}

Matrix3x3::Matrix3x3(const double values[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m[i][j] = values[i][j];
        }
    }
}

double Matrix3x3::get(int row, int col) const {
    return m[row][col];
}

void Matrix3x3::set(int row, int col, double value) {
    m[row][col] = value;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.set(i, j, m[i][j] + other.get(i, j));
        }
    }
    return result;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.set(i, j, m[i][j] - other.get(i, j));
        }
    }
    return result;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.set(i, j, 0); // Başlangıçta sıfırla
            for (int k = 0; k < 3; ++k) {
                result.set(i, j, result.get(i, j) + m[i][k] * other.get(k, j));
            }
        }
    }
    return result;
}

void Matrix3x3::print() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
