#include <iostream>
#include "wektor.h"

int main()
{
    // Przykładowe użycie klasy Vector3D
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);

    Vector3D v3 = v1.add(v2);
    v3.print();

    double length = v1.length();
    std::cout << "Długość v1: " << length << std::endl;

    return 0;
}
