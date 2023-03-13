#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Student
{
    string imie;
    string nazwisko;
    int numer_albumu;
    int dzien_urodzenia;
    int miesiac_urodzenia;
    int rok_urodzenia;
};

struct BazaStudentow
{
    string nazwa_uczelni;
    Student studenci[100];
    int liczba_studentow;
};

void display_student(Student s)
{
    cout << "Imie: " << s.imie << endl;
    cout << "Nazwisko: " << s.nazwisko << endl;
    cout << "Numer albumu: " << s.numer_albumu << endl;
    cout << "Data urodzenia: " << s.dzien_urodzenia << "-" << s.miesiac_urodzenia << "-" << s.rok_urodzenia << endl;
}

Student read_student()
{
    Student s;
    cout << "Podaj imie: ";
    while (!(cin >> s.imie))
    {
        cout << "Nieprawidlowe dane. Podaj imie ponownie: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Podaj nazwisko: ";
    while (!(cin >> s.nazwisko))
    {
        cout << "Nieprawidlowe dane. Podaj nazwisko ponownie: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Podaj numer albumu : ";
    while (!(cin >> s.numer_albumu))
    {
        cout << "Nieprawidlowe dane. Podaj numer albumu ponownie: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Podaj dzien urodzenia: ";
    while (!(cin >> s.dzien_urodzenia))
    {
        cout << "Nieprawidlowe dane. Podaj dzien urodzenia ponownie: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Podaj miesiac urodzenia: ";
    while (!(cin >> s.miesiac_urodzenia))
    {
        cout << "Nieprawidlowe dane. Podaj miesiac urodzenia ponownie: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Podaj rok urodzenia: ";
    while (!(cin >> s.rok_urodzenia))
    {
        cout << "Nieprawidlowe dane. Podaj rok urodzenia ponownie: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return s;
}

void display_all_students(Student studenci[], int liczba_studentow)
{
    for (int i = 0; i < liczba_studentow; i++)
    {
        cout << "Student " << i << ":" << endl;
        display_student(studenci[i]);
        cout << endl;
    }
}

void add_student(BazaStudentow &baza)
{
    if (baza.liczba_studentow >= 100) // Sprawdzamy, czy w bazie nie ma już maksymalnej liczby studentów
    {
        cout << "Nie mozna dodac kolejnego studenta. Baza jest pelna." << endl;
        return;
    }

    Student nowy_student = read_student(); // Wczytujemy dane nowego studenta

    baza.studenci[baza.liczba_studentow] = nowy_student; // Dodajemy nowego studenta do tablicy w bazie
    baza.liczba_studentow++;                             // Zwiększamy liczbę studentów w bazie o 1
}

int find_student(BazaStudentow baza, int numer_albumu)
{
    for (int i = 0; i < baza.liczba_studentow; i++)
    {
        if (baza.studenci[i].numer_albumu == numer_albumu)
        {
            return i; // zwróć pozycję studenta w bazie
        }
    }

    return -1; // student nie istnieje w bazie
}
void remove_student(BazaStudentow &baza, int numer_albumu)
{
    int pozycja_studenta = find_student(baza, numer_albumu);

    if (pozycja_studenta == -1)
    {
        cout << "Nie ma studenta o numerze albumu " << numer_albumu << " w bazie." << endl;
        return;
    }

    for (int i = pozycja_studenta; i < baza.liczba_studentow - 1; i++)
    {
        baza.studenci[i] = baza.studenci[i + 1];
    }

    baza.liczba_studentow--;
    cout << "Student o numerze albumu " << numer_albumu << " został usunięty z bazy." << endl;
}
void load_students(BazaStudentow &baza)
{
    ifstream plik("student_loud.txt");
    if (!plik.good())
    {
        cout << "Nie udalo sie otworzyc pliku student_loud.txt." << endl;
        return;
    }

    string line;
    int i = 0;
    while (getline(plik, line))
    {
        stringstream ss(line);
        string imie, nazwisko;
        int numer_albumu, dzien_urodzenia, miesiac_urodzenia, rok_urodzenia;
        ss >> imie >> nazwisko >> numer_albumu >> dzien_urodzenia >> miesiac_urodzenia >> rok_urodzenia;

        baza.studenci[i].imie = imie;
        baza.studenci[i].nazwisko = nazwisko;
        baza.studenci[i].numer_albumu = numer_albumu;
        baza.studenci[i].dzien_urodzenia = dzien_urodzenia;
        baza.studenci[i].miesiac_urodzenia = miesiac_urodzenia;
        baza.studenci[i].rok_urodzenia = rok_urodzenia;

        i++;
        if (i == 100)
        {
            break;
        }
    }

    baza.liczba_studentow = i;
    plik.close();
}

void save_students(BazaStudentow baza)
{
    ofstream plik("student_saved.txt");
    if (!plik.good())
    {
        cout << "Nie udalo sie otworzyc pliku student_saved.txt." << endl;
        return;
    }

    for (int i = 0; i < baza.liczba_studentow; i++)
    {
        plik << baza.studenci[i].imie << '\t' << baza.studenci[i].nazwisko << '\t'
             << baza.studenci[i].numer_albumu << '\t' << baza.studenci[i].dzien_urodzenia << '\t'
             << baza.studenci[i].miesiac_urodzenia << '\t' << baza.studenci[i].rok_urodzenia << endl;
    }

    plik.close();
}

int main()
{
    BazaStudentow baza;
    baza.nazwa_uczelni = "Politechnika Warszawska";
    baza.liczba_studentow = 0;

    int wybor = -1;

    while (wybor != 0)
    {
        cout << "Menu:" << endl;
        cout << "1. Wyświetl bazę studentów" << endl;
        cout << "2. Dodaj studenta" << endl;
        cout << "3. Usuń studenta" << endl;
        cout << "4. Znajdź studenta" << endl;
        cout << "5. Wczytaj studentów z pliku" << endl;
        cout << "6. Zapisz bazę studentów do pliku" << endl;
        cout << "0. Wyjdź z programu" << endl;

        cin >> wybor;

        switch (wybor)
        {
        case 1:
            display_all_students(baza.studenci, baza.liczba_studentow);
            break;
        case 2:
            add_student(baza);
            break;
        case 3:
            int numer_albumu_do_usuniecia;
            cout << "Podaj numer albumu studenta do usunięcia: ";
            cin >> numer_albumu_do_usuniecia;
            remove_student(baza, numer_albumu_do_usuniecia);
            break;
        case 4:
        {
            int numer_albumu_do_znalezienia;
            cout << "Podaj numer albumu studenta do znalezienia: ";
            cin >> numer_albumu_do_znalezienia;
            int pozycja_studenta = find_student(baza, numer_albumu_do_znalezienia);
            if (pozycja_studenta == -1)
            {
                cout << "Nie ma studenta o numerze albumu " << numer_albumu_do_znalezienia << " w bazie." << endl;
            }
            else
            {
                cout << "Student o numerze albumu " << numer_albumu_do_znalezienia << " istnieje w bazie." << endl;
            }
            break;
        }

        case 5:
            cout << "Wczytywanie danych" << endl;
            load_students(baza);
            cout << "Wczytano" << endl;
            break;
        case 6:
            cout << "Zapisywanie danych" << endl;
            save_students(baza);
            cout << "Zapisano" << endl;
            break;
        case 0:
            cout << "Koniec programu" << endl;
            break;
        default:
            cout << "Nieprawidłowa opcja" << endl;
            break;
        }
    }

    return 0;
}
