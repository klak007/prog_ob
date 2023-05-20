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

// Przeciążony operator dodawania
Vector3D Vector3D::operator+(const Vector3D &other) const
{
    double newX = x + other.x;
    double newY = y + other.y;
    double newZ = z + other.z;
    return Vector3D(newX, newY, newZ);
}

// Przeciążony operator odejmowania
Vector3D Vector3D::operator-(const Vector3D &other) const
{
    double newX = x - other.x;
    double newY = y - other.y;
    double newZ = z - other.z;
    return Vector3D(newX, newY, newZ);
}

// Przeciążony operator iloczynu wektorowego
Vector3D Vector3D::operator*(const Vector3D &other) const
{
    double newX = y * other.z - z * other.y;
    double newY = z * other.x - x * other.z;
    double newZ = x * other.y - y * other.x;
    return Vector3D(newX, newY, newZ);
}

// Przeciążony operator mnożenia przez skalar
Vector3D Vector3D::operator*(double scalar) const
{
    double newX = x * scalar;
    double newY = y * scalar;
    double newZ = z * scalar;
    return Vector3D(newX, newY, newZ);
}

std::ostream &operator<<(std::ostream &os, const Vector3D &vector)
{
    os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
    return os;
}

double Vector3D::operator[](int index) const
{
    if (index == 0)
        return x;
    else if (index == 1)
        return y;
    else if (index == 2)
        return z;
    else
        throw std::out_of_range("Invalid index");
}

// Metoda do obliczania długości wektora
double Vector3D::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}
