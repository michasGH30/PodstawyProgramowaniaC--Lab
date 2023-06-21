#include <iostream>
#include <cstdlib>

using namespace std;

int liczby(int *suma, int *iloczyn)
{
    int s = 0;
    int il = 1;
    int l;
    int ile = 0;
    cout << "Podaj liczbe: ";
    cin >> l;
    ile++;
    s += l;
    il *= l;
    while (l != 0)
    {
        cout << "Podaj liczbe: ";
        cin >> l;
        if (l != 0)
        {
            s += l;
            il *= l;
            ile++;
        }
    }
    *suma = s;
    *iloczyn = il;
    if (ile % 2 == 0)
        return 0;
    return 1;
}

void wypisz(int w, int *s, int *l)
{
    if (w == 0)
        cout << "Była parzysta liczba elementów";
    else
        cout << "Była nieparzysta liczba elementów";
    cout << '\n';
    cout << "Suma elementów wyniosła: " << *s << '\n';
    cout << "Iloczyn elementów wyniosła: " << *l << '\n';
}

int main()
{
    setlocale(LC_ALL, "Polish");
    int *suma, *iloczyn;
    int t, t1;
    suma = &t;
    iloczyn = &t1;
    int wynik = liczby(suma, iloczyn);
    wypisz(wynik, suma, iloczyn);
    return 0;
}