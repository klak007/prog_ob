#include "wektor.h"
#include <iostream>
#include <cmath>

// Konstruktor
Vector3D::Vector3D(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal) {}

// Metody dostępowe
double Vector3D::getX() const { return x; }
double Vector3D::getY() const { return y; }
double Vector3D::getZ() const { return z; }

// Metoda do wyświetlania wektora
void Vector3D::print() const
{
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// Metoda do dodawania dwóch wektorów
Vector3D Vector3D::add(const Vector3D &other) const
{
    double newX = x + other.x;
    double newY = y + other.y;
    double newZ = z + other.z;
    return Vector3D(newX, newY, newZ);
}

// Metoda do obliczania długości wektora
double Vector3D::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}
