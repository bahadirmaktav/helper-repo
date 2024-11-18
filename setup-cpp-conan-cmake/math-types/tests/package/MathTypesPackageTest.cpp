#include <iostream>

#include "algebra/Vector3D.h"

int main() {
    Vector3D vector_a{1.0, 2.0, 3.0};
    std::cout << "vector_a : ";
    vector_a.print();
    Vector3D vector_b{3.0, 4.0, 5.0};
    std::cout << "vector_b : ";
    vector_b.print();
    Vector3D vector_sum = vector_a + vector_b;
    std::cout << "vector_sum : ";
    vector_sum.print();
    std::cout << "Package test completed!" << std::endl;
    return 0;
}
