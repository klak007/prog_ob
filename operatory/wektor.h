#ifndef WEKTOR_H
#define WEKTOR_H

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

    // Metoda do dodawania dwóch wektorów
    Vector3D add(const Vector3D &other) const;

    // Metoda do obliczania długości wektora
    double length() const;
};

#endif
