#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int **ret_tab(int *n, int *m)
{
    int **tab = new int *[*n];
    for (int i = 0; i < *n; i++)
    {
        tab[i] = new int[*m];
    }

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            tab[i][j] = rand() % 9;
            cout << tab[i][j] << " ";
        }
        cout << '\n';
    }
    return tab;
}

void rozmiary(int *n, int *m)
{
    cout << "Podaj liczbę wierszy: ";
    cin >> *n;
    cout << "Podaj liczbę kolumn: ";
    cin >> *m;
}

void podaj(int *n, int *m, int *pw, int *pk)
{
    do
    {
        cout << "Podaj wiersz do wypisania: ";
        cin >> *pw;
    } while (!(*pw >= 0 && *pw < *n));
    do
    {
        cout << "Podaj kolumnę do wypisania: ";
        cin >> *pk;
    } while (!(*pk >= 0 && *pk < *m));
}

void wyswielt(int *pw, int *pk, int *n, int *m, int **tab)
{
    for (int j = 0; j < *m; j++)
    {
        cout << tab[*pw][j] << " ";
    }
    cout << '\n';
    for (int i = 0; i < *n; i++)
    {
        cout << tab[i][*pk] << '\n';
    }
}

void zwolnij(int **tab, int *n)
{
    for (int i = 0; i < *n; i++)
        delete[] tab[i];
    delete[] tab;
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int n = -1, m = -1;
    rozmiary(&n, &m);
    int **tab = ret_tab(&n, &m);
    int podany_w = -1;
    int podany_k = -1;
    podaj(&n, &m, &podany_w, &podany_k);
    wyswielt(&podany_w, &podany_k, &n, &m, tab);
    zwolnij(tab, &n);
    return 0;
}