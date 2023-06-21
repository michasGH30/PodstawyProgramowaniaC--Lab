#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student
{
    string imie;
    string nazwisko;
    string nr_albumu;
    int ile_egzaminow;
    int *oceny;

public:
    Student()
    {
        imie = "Michał";
        nazwisko = "Żuk";
        nr_albumu = "87604";
        ile_egzaminow = 5;
        oceny = new int[ile_egzaminow];
        generuj_oceny();
    }
    Student(string i, string n, string nr, int ile)
    {
        imie = i;
        nazwisko = n;
        nr_albumu = nr;
        ile_egzaminow = ile;
        oceny = new int[ile_egzaminow];
        generuj_oceny();
    }
    void wyswietl()
    {
        cout << imie << " " << nazwisko << " numer albumu: " << nr_albumu << " ilość egzaminów: " << ile_egzaminow << " oceny: ";
        for (int i = 0; i < ile_egzaminow; i++)
        {
            cout << oceny[i] << " ";
        }
        cout << '\n';
    }
    void generuj_oceny()
    {
        for (int i = 0; i < ile_egzaminow; i++)
        {
            oceny[i] = rand() % 3 + 2;
        }
    }
    void podaj_dane()
    {
        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj numer albumu: ";
        cin >> nr_albumu;
        do
        {
            cout << "Podaj ilość egzaminów: ";
            cin >> ile_egzaminow;

        } while (ile_egzaminow < 0);
        generuj_oceny();
    }
    float srednia()
    {
        float suma = 0;
        for (int i = 0; i < ile_egzaminow; i++)
        {
            suma += oceny[i];
        }
        return suma / (float)ile_egzaminow;
    }
    bool oceny_ndst()
    {
        int ile = 0;
        for (int i = 0; i < ile_egzaminow; i++)
        {
            if (oceny[i] == 2)
                ile++;
        }
        if (ile > 2)
            return true;
        return false;
    }
    ~Student()
    {
        delete[] oceny;
    }
};
int ile_uczniow()
{
    cout << "Podaj ilość uczniów: ";
    int n = 0;
    cin >> n;
    return n;
}
void uzupelnij_uczniow(Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i].podaj_dane();
    }
}

void srednia(Student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Dla studenta: ";
        s[i].wyswietl();
        cout << "Średnia wynosi: ";
        cout << s[i].srednia() << '\n';
    }
}

void ndst(Student *s, int n)
{
    int ile = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].oceny_ndst())
            ile++;
    }
    cout << ile << " studentów ma więcej niż 2 oceny ndst\n";
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int n = ile_uczniow();
    Student *studenci = new Student[n];
    uzupelnij_uczniow(studenci, n);
    srednia(studenci, n);
    ndst(studenci, n);
    return 0;
}