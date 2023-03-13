#include <string>
#include <vector>

struct Student
{
    std::string imie;
    std::string nazwisko;
    int numer_albumu;
    int rok_urodzenia;
    int miesiac_urodzenia;
    int dzien_urodzenia;
};

struct BazaStudentow
{
    std::string nazwa_uczelni;
    std::vector<Student> studenci;
};

void add_student(BazaStudentow &baza, const Student &student)
{
    baza.studenci.push_back(student);
}

int find_student(const BazaStudentow &baza, int numer_albumu)
{
    for (int i = 0; i < baza.studenci.size(); ++i)
    {
        if (baza.studenci[i].numer_albumu == numer_albumu)
        {
            return i;
        }
    }
    return -1;
}

void remove_student(BazaStudentow &baza, int numer_albumu)
{
    int index = find_student(baza, numer_albumu);
    if (index != -1)
    {
        baza.studenci.erase(baza.studenci.begin() + index);
    }
}

void load_students(BazaStudentow &baza, const std::string &nazwa_pliku)
{
    // kod wczytujący dane studentów z pliku i dodający je do bazy
}

void save_students(const BazaStudentow &baza, const std::string &nazwa_pliku)
{
    // kod zapisujący dane studentów z bazy do pliku
}
