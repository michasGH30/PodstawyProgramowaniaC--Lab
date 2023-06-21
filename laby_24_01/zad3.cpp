#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int podaj_n()
{
    cout << "Podaj n: ";
    int n = 0;
    cin >> n;
    return n;
}

void losuj(int *tab, int n)
{
    if (n >= 0)
    {
        tab[n] = rand() % 17 - 4;
        losuj(tab, n - 1);
    }
}

void wypisz(int *tab, int n)
{
    if (n >= 0)
    {
        if (tab[n] % (-6) == 0 && n % 2 != 0)
        {
            cout << tab[n] << " ";
            cout << n << " ";
        }
        wypisz(tab, n - 1);
    }
}

void wypisz_zawsze(int *tab, int n)
{
    if (n >= 0)
    {
        cout << tab[n] << " ";
        wypisz_zawsze(tab, n - 1);
    }
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int n = podaj_n();
    int *tab = new int[n];
    losuj(tab, n - 1);
    wypisz(tab, n - 1);
    cout << '\n';
    wypisz_zawsze(tab, n - 1);
    delete[] tab;
    return 0;
}