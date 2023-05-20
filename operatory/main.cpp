#include <iostream>
#include "wektor.h"

int main()
{
    // Przykładowe użycie klasy Vector3D
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    std::cout << "Wartość x: " << v1[0] << std::endl;
    std::cout << "Wartość y: " << v1[1] << std::endl;
    std::cout << "Wartość z: " << v1[2] << std::endl;

    double scalar = 2.5;

    Vector3D v3 = v1 + v2;
    Vector3D v4 = v1 - v2;
    Vector3D v5 = v1 * v2;
    Vector3D v6 = v1 * scalar;

    std::cout << "Wektor v1: " << v1 << std::endl;
    std::cout << "Wektor v2: " << v2 << std::endl;
    std::cout << "Wektor v3: " << v3 << std::endl;
    std::cout << "Wektor v4: " << v4 << std::endl;
    std::cout << "Wektor v5: " << v5 << std::endl;
    std::cout << "Wektor v6: " << v6 << std::endl;

    double length = v1.length();
    std::cout << "Długość v1: " << length << std::endl;

    return 0;
}
