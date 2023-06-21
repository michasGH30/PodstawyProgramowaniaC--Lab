#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Student
{
    char imie[10];
    char nazwisko[20];
    char PESEL[11];
    int rok;
    float srednia;
};

void utworz_baze(string nazwaT, string nazwaB)
{
    fstream plikT;
    plikT.open(nazwaT.c_str(), ios::in);
    if (!plikT.good())
    {
        cout << "Błąd z plikiem.";
        exit(-1);
    }

    fstream plikB;
    plikB.open(nazwaB.c_str(), ios::binary | ios::out);

    Student s;
    while (!plikT.eof())
    {
        plikT >> s.imie >> s.nazwisko >> s.PESEL >> s.rok >> s.srednia;
        cout << s.imie << " " << s.nazwisko << " " << s.PESEL << " " << s.rok << " " << s.srednia << '\n';
        plikB.write(reinterpret_cast<char *>(&s), sizeof(s));
    }

    plikT.close();
    plikB.close();
}

int main()
{
    setlocale(LC_ALL, "Polish");
    utworz_baze("zad12.txt", "zad12.dat");
    return 0;
}