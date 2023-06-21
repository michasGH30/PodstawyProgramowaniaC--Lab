#include <iostream>
#include <cstdlib>

using namespace std;

int NWD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

void skroc(int *l, int *m)
{
    cout << "Ułamek przed: " << *l << "/" << *m << '\t';
    int dzielnik = NWD(*l, *m);
    (*l) /= dzielnik;
    (*m) /= dzielnik;
    cout << "Ułamek po: " << *l << "/" << *m << '\n';
}

void podaj(int *l, int *m)
{
    cout << "Podaj licznik: ";
    cin >> *l;
    do
    {
        cout << "Podaj mianownik: ";
        cin >> *m;
    } while (*m == 0);
}

int main()
{
    setlocale(LC_ALL, "Polish");
    int L = 0, M = 0;
    podaj(&L, &M);
    skroc(&L, &M);
    return 0;
}