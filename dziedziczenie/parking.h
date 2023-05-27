#ifndef PARKING_H
#define PARKING_H

#include <vector>
#include "pojazd.h"

class Parking
{
private:
    const int szerokoscMiejsca = 3; // Szerokość miejsca parkingowego w metrach
    const int dlugoscMiejsca = 6;   // Długość miejsca parkingowego w metrach
    std::vector<Pojazd *> tab;      // Wektor wskaźników na pojazdy zaparkowane na parkingu

public:
    Parking();
    bool czyMiejsceWolne(int x, int y);
    void zaparkujPojazd(Pojazd *pojazd, int x, int y);
    std::vector<Pojazd *> getTab();
    void wyswietlPojazdy();
    void wyswietlInformacjeOMiejscu(int x, int y);
};

#endif // PARKING_H
