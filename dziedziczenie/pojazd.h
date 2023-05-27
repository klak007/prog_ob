#ifndef POJAZD_H
#define POJAZD_H

#include <string>

class Pojazd
{
public:
    std::string numerRejestracyjny;
    int liczbaKol;
    int liczbaOsi;

public:
    Pojazd(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi);
    std::string getNumerRejestracyjny();
    int getLiczbaKol();
    int getLiczbaOsi();
    virtual void info();
};

class Motocykl : public Pojazd
{
private:
    int szerokoscParkingu;

public:
    Motocykl(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int szerokoscParkingu);
    void info() override;
};

class Osobowy : public Pojazd
{
private:
    int przebieg;

public:
    Osobowy(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int przebieg);
    void info() override;
};

class Dostawczy : public Pojazd
{
private:
    int dopuszczalnaMasaCalkowita;
    int dlugoscZNaczepa;

public:
    Dostawczy(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int dopuszczalnaMasaCalkowita, int dlugoscZNaczepa);
    void info() override;
};

class Autobus : public Pojazd
{
private:
    int liczbaMiejscSiedzacych;
    int liczbaMiejscStojacych;
    int dlugosc;

public:
    Autobus(std::string numerRejestracyjny, int liczbaKol, int liczbaOsi, int liczbaMiejscSiedzacych, int liczbaMiejscStojacych, int dlugosc);
    void info() override;
};

#endif // POJAZD_H
