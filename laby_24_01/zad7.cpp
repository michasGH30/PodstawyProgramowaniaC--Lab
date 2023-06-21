#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int podaj_n()
{
    cout << "Podaj n: ";
    int n = 0;
    cin >> n;
    return n;
}

void losuj(float **tab, int i, int j, int n)
{
    if (i <= n)
    {
        if (j > n)
        {
            cout << '\n';
            losuj(tab, i + 1, 0, n);
        }
        else
        {
            if (i + j > n)
                tab[i][j] = 0;
            else
                tab[i][j] = rand() / (float)RAND_MAX * 9.0;

            cout << fixed << setprecision(2) << tab[i][j] << " ";
            losuj(tab, i, j + 1, n);
        }
    }
}

void kopiuj(float **tab, int i, int j, int n)
{
    if (i <= n)
    {
        if (j > n)
        {
            kopiuj(tab, i + 1, 0, n);
        }
        else
        {
            if (i + j < n)
            {
                int k = n - (i + j);
                int i_t = k + i;
                int j_t = k + j;
                tab[i_t][j_t] = tab[i][j];
            }
            kopiuj(tab, i, j + 1, n);
        }
    }
}

void wypisz(float **tab, int i, int j, int n)
{
    if (i <= n)
    {
        if (j > n)
        {
            cout << '\n';
            wypisz(tab, i + 1, 0, n);
        }
        else
        {
            cout << fixed << setprecision(2) << tab[i][j] << " ";
            wypisz(tab, i, j + 1, n);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int n = podaj_n();
    float **tab = new float *[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = new float[n];
    }

    losuj(tab, 0, 0, n - 1);
    kopiuj(tab, 0, 0, n - 1);
    cout << '\n';
    wypisz(tab, 0, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;

    return 0;
}