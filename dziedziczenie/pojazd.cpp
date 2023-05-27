#include "pojazd.h"
#include <iostream>

// Implementacja metod klasy Pojazd
Pojazd::Pojazd(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi)
    : numerRejestracyjny(numerRejestracyjny), liczbaKol(liczbaKol), liczbaOsi(liczbaOsi) {}

std::string Pojazd::getNumerRejestracyjny()
{
    return numerRejestracyjny;
}

int Pojazd::getLiczbaKol()
{
    return liczbaKol;
}

int Pojazd::getLiczbaOsi()
{
    return liczbaOsi;
}

void Pojazd::info()
{
    std::cout << "Numer rejestracyjny: " << numerRejestracyjny << std::endl;
    std::cout << "Liczba kół: " << liczbaKol << std::endl;
    std::cout << "Liczba osi: " << liczbaOsi << std::endl;
}

// Implementacja metod klasy Motocykl
Motocykl::Motocykl(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int szerokoscParkingu)
    : Pojazd(numerRejestracyjny, liczbaKol, liczbaOsi), szerokoscParkingu(szerokoscParkingu) {}

void Motocykl::info()
{
    Pojazd::info();
    std::cout << "Szerokość potrzebna na parkingu: " << szerokoscParkingu << " m" << std::endl;
}

// Implementacja metod klasy Osobowy
Osobowy::Osobowy(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int przebieg)
    : Pojazd(numerRejestracyjny, liczbaKol, liczbaOsi), przebieg(przebieg) {}

void Osobowy::info()
{
    Pojazd::info();
    std::cout << "Przebieg: " << przebieg << " km" << std::endl;
}

// Implementacja metod klasy Dostawczy
Dostawczy::Dostawczy(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int dopuszczalnaMasaCalkowita, int dlugoscZNaczepa)
    : Pojazd(numerRejestracyjny, liczbaKol, liczbaOsi), dopuszczalnaMasaCalkowita(dopuszczalnaMasaCalkowita), dlugoscZNaczepa(dlugoscZNaczepa) {}

void Dostawczy::info()
{
    Pojazd::info();
    std::cout << "Dopuszczalna masa całkowita: " << dopuszczalnaMasaCalkowita << " kg" << std::endl;
    std::cout << "Długość z naczepą: " << dlugoscZNaczepa << " m" << std::endl;
}

// Implementacja metod klasy Autobus
Autobus::Autobus(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int liczbaMiejscSiedzacych, int liczbaMiejscStojacych, int dlugosc)
    : Pojazd(numerRejestracyjny, liczbaKol, liczbaOsi), liczbaMiejscSiedzacych(liczbaMiejscSiedzacych), liczbaMiejscStojacych(liczbaMiejscStojacych), dlugosc(dlugosc) {}

void Autobus::info()
{
    Pojazd::info();
    std::cout << "Liczba miejsc siedzących: " << liczbaMiejscSiedzacych << std::endl;
    std::cout << "Liczba miejsc stojących: " << liczbaMiejscStojacych << std::endl;
    std::cout << "Długość autobusu: " << dlugosc << " m" << std::endl;
}
