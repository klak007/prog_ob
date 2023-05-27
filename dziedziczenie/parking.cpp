#include "parking.h"
#include <iostream>

Parking::Parking() {}

bool Parking::czyMiejsceWolne(int x, int y)
{
    if (x >= tab.size() || tab[x] == nullptr || y >= tab[x]->getLiczbaKol())
        return true;
    return false;
}

void Parking::zaparkujPojazd(Pojazd *pojazd, int x, int y)
{
    if (czyMiejsceWolne(x, y))
    {
        if (x >= tab.size())
        {
            tab.resize(x + 1, nullptr);
        }
        if (tab[x] == nullptr)
        {
            tab[x] = pojazd;
        }
        else
        {
            tab[x]->liczbaKol = y + 1;
        }
        std::cout << "Pojazd zaparkowany na miejscu [" << x << ", " << y << "]" << std::endl;
    }
    else
    {
        std::cout << "Miejsce parkingowe [" << x << ", " << y << "] jest zajęte" << std::endl;
    }
}

std::vector<Pojazd *> Parking::getTab()
{
    return tab;
}
void Parking::wyswietlPojazdy()
{
    int szerokosc = 10; // Szerokość parkingu
    int wysokosc = 2;   // Wysokość parkingu
    tab.resize(szerokoscMiejsca * dlugoscMiejsca, nullptr);
    for (int y = 0; y < wysokosc; ++y)
    {
        for (int x = 0; x < szerokosc; ++x)
        {
            if (!czyMiejsceWolne(x, y))
            {
                std::cout << "Miejsce parkingowe [" << x << ", " << y << "] zajmowane przez pojazd" << std::endl;
                tab[y * szerokosc + x]->info();
                std::cout << std::endl;
            }
        }
    }
}

void Parking::wyswietlInformacjeOMiejscu(int x, int y)
{
    if (!czyMiejsceWolne(x, y))
    {
        std::cout << "Informacje o miejscu parkingowym [" << x << ", " << y << "]" << std::endl;
        tab[y * szerokoscMiejsca + x]->info();
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Miejsce parkingowe [" << x << ", " << y << "] jest wolne" << std::endl;
    }
}