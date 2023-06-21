#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void srednie_stypendium(string nazwa, string wynik)
{
    fstream plik;
    plik.open(nazwa.c_str(), ios::in);
    if (!plik.good())
    {
        cout << "Problem z plikiem!!!!";
        exit(-1);
    }
    char imie[10];
    char naz[20];
    int s;
    string kierunek;
    float stypednium = 0;
    int n = 0;
    while (!plik.eof())
    {
        plik >> imie >> naz >> s >> kierunek;
        n++;
        stypednium += (float)s;
    }
    stypednium /= (float)n;
    plik.close();
    plik.open(wynik.c_str(), ios::out);
    plik << "Średnie stupendium wynosi: " << stypednium << " zł";
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srednie_stypendium("zad2.txt", "zad2_wynik.txt");
    return 0;
}