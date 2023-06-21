#include <iostream>
#include <cstdlib>

using namespace std;
/*3. wypisze samochody o maksymalnej cenie dla danej marki (jak więcej, to wszystkie).*/
struct Samochod
{
    string marka;
    string typ;
    float cena;
};

int ile_s()
{
    cout << "Podaj ilość samochodów: ";
    int n = 0;
    cin >> n;
    return n;
}

Samochod *generuj(int n)
{
    Samochod *s = new Samochod[n];
    return s;
}

void wprowadz_dane(Samochod *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Podaj markę " << i + 1 << " samochodu: ";
        cin >> (s + i)->marka;
        cout << "Podaj typ " << i + 1 << " samochodu: ";
        cin >> (s + i)->typ;
        cout << "Podaj cenę " << i + 1 << " samochodu: ";
        cin >> (s + i)->cena;
    }
}

void wypisz_typ(Samochod *s, int n, string t)
{
    for (int i = 0; i < n; i++)
    {
        if ((s + i)->typ == t)
        {
            cout << "Marka " << i + 1 << " samochodu: " << (s + i)->marka << '\t';
            cout << "Typ " << i + 1 << " samochodu: " << (s + i)->typ << '\t';
            cout << "Cena " << i + 1 << " samochodu: " << (s + i)->cena << '\n';
        }
    }
}

void wypisz_cena(Samochod *s, int n, string ma)
{
    float m;
    if (s->marka == ma)
        m = s->cena;
    else
        m = 0;
    for (int i = 1; i < n; i++)
    {
        if ((s + i)->marka == ma && (s + i)->cena > m)
        {
            m = (s + i)->cena;
        }
    }
    cout << "Największa cena dla marki: " << ma << " wynosi: " << m << '\n';
}