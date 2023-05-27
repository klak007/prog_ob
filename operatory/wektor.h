#ifndef WEKTOR_H
#define WEKTOR_H
#include <iostream>

class Vector3D
{
private:
    double x;
    double y;
    double z;

public:
    // Konstruktor
    Vector3D(double xVal, double yVal, double zVal);

    // Metody dostępowe
    double getX() const;
    double getY() const;
    double getZ() const;

    // Metoda do wyświetlania wektora
    void print() const;

    // Przeciążone operatory
    Vector3D operator+(const Vector3D &other) const;
    Vector3D operator-(const Vector3D &other) const;
    Vector3D operator*(const Vector3D &other) const;
    Vector3D operator*(double scalar) const;
    double operator[](int index) const;
    friend std::ostream &operator<<(std::ostream &os, const Vector3D &vector);

    // Metoda do obliczania długości wektora
    double length() const;
};

#endif
