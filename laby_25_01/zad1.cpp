#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void czytaj(string nazwa, int *ile, float *cyfry, float *litery, float *pozostale)
{
    fstream plik;
    plik.open(nazwa.c_str(), ios::in);
    if (!plik.good())
    {
        cout << "Problem z plikiem!!!";
        exit(-1);
    }
    string linia;
    while (getline(plik, linia))
    {
        for (int i = 0; i < linia.length(); i++)
        {
            if (isalpha((char)linia[i]))
            {
                (*litery)++;
            }
            else if (isdigit((char)linia[i]))
            {
                (*cyfry)++;
            }
            else
            {
                (*pozostale)++;
                if ((char)linia[i] == ' ' || (char)linia[i] == ',' || (char)linia[i] == '.')
                {
                    (*pozostale)--;
                }
            }
            (*ile)++;
        }
    }
    plik.close();
}

void wypisz(int ile, float cyfry, float litery, float pozostale)
{
    cout << "Łącznie: " << ile << '\n';
    cout << fixed << setprecision(2);
    cout << "Cyfry było: " << cyfry << " co stanowi: " << cyfry / (float)ile * 100.0 << " %\n";
    cout << "Liter było: " << litery << " co stanowi: " << litery / (float)ile * 100.0 << " %\n";
    cout << "Pozostałych znaków (bez spacji, przecinka i kropki) było : " << pozostale << "  co stanowi: " << pozostale / (float)ile * 100.0 << " %";
}

int main()
{
    setlocale(LC_ALL, "Polish");
    int ile = 0;
    float cyfry = 0;
    float litery = 0;
    float pozostale = 0;
    czytaj("zad1_baza.txt", &ile, &cyfry, &litery, &pozostale);
    wypisz(ile, cyfry, litery, pozostale);
    return 0;
}