#include "MathFunctions.h"

#include <cmath>

namespace MathFunctions {

double sqrt(double x) {
  return std::sqrt(x);
}
Types::Matrix GetZeroMatrix() {
  return Types::Matrix(0, 0);
}

}