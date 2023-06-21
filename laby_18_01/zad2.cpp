#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

float norma(float *tab, int n, int met = 1)
{
    float nor = 0;
    switch (met)
    {
    case 0:
        nor = fabs(tab[0]);
        for (int i = 1; i < n; i++)
        {
            if (fabs(tab[i]) > n)
                nor = fabs(tab[i]);
        }
        break;
    case 1:
        float s = 0;
        for (int i = 0; i < n; i++)
        {
            s += pow(tab[i], 2);
        }
        nor = sqrt(s);
        break;
    }
    return nor;
}

float *generuj(int n)
{
    float *t = new float[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = rand() / (float)RAND_MAX * 20.0 - 10.0;
    }
    return t;
}

void wyswietl(float *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
}

int podaj_n()
{
    cout << "Podaj ilość elemtentów wektora: ";
    int n = 0;
    cin >> n;
    return n;
}

void wyswietl_norme(float nor, float *tab, int n, int k = 1)
{
    cout << "Norma dla wektora: ";
    wyswietl(tab, n);
    cout << " wynosi: " << nor;
    if (k == 0)
        cout << " - maksymalna bezwzględna wartość";
    else
        cout << " - pierwiastek z sumy kwadratów";
    cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int n = podaj_n();
    float *tab = generuj(n);

    float nor = norma(tab, n);
    wyswietl_norme(nor, tab, n);

    nor = norma(tab, n, 0);
    wyswietl_norme(nor, tab, n, 0);
    return 0;
}