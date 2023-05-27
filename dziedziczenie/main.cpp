#include "parking.h"
#include <iostream>
#include <vector>

int main()
{
    Parking parking;

    // Tworzenie różnych typów pojazdów
    Motocykl motocykl("MOT123", 2, 1, 1);
    Osobowy osobowy("OSO567", 4, 2, 50000);
    Dostawczy dostawczy("DOS901", 4, 2, 2000, 6);
    Autobus autobus("BUS345", 6, 3, 30, 10, 12);

    // Parkowanie pojazdów
    parking.zaparkujPojazd(&motocykl, 0, 0);
    // parking.zaparkujPojazd(&osobowy, 0, 1);
    parking.zaparkujPojazd(&dostawczy, 1, 0);
    parking.zaparkujPojazd(&autobus, 2, 1);

    // Wyświetlanie informacji o pojazdach na parkingu
    std::vector<Pojazd *> zaparkowanePojazdy = parking.getTab();
    for (Pojazd *pojazd : zaparkowanePojazdy)
    {
        pojazd->info();
        std::cout << std::endl;
    }
    // Wyświetlanie informacji o konkretnych miejscach parkingowych
    // parking.wyswietlInformacjeOMiejscu(0, 0);
    // parking.wyswietlInformacjeOMiejscu(1, 0);
    // parking.wyswietlInformacjeOMiejscu(0, 1);
    // parking.wyswietlInformacjeOMiejscu(1, 1);

    return 0;
}
