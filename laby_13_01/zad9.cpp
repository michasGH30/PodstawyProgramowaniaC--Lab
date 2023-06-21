#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void uzupelnij(float *t, int n)
{
    float d = 4000.0 / (float)n;
    bool powt = false;
    for (int i = 0; i < n; i++)
    {
        do
        {
            powt = false;
            t[i] = rand() / (float)RAND_MAX * d + (1000.0 + i * d);
            float temp = t[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (temp == t[j])
                    powt = true;
            }
        } while (powt);
    }
}

void wypisz(float *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
    cout << '\n';
}

float srednia(float *t, int n)
{
    float srednia = 0;
    for (int i = 0; i < n; i++)
    {
        srednia += t[i];
    }
    srednia /= (float)n;
    return srednia;
}

float mediana(float *t, int n)
{
    if (n % 2 == 0)
        return (t[n / 2] + t[n / 2 - 1]) / (float)2;
    return t[n / 2];
}

void wyp(string t, float k)
{
    cout << t << k << '\n';
}

void zarobki(float m, float s)
{
    if (s > m)
    {
        cout << "Przynajmniej połowa pracowników ma zarobki powyżej średniej\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int n = 0;
    cout << "Podaj ilość pracowników: ";
    cin >> n;
    float *tab = new float[n];
    uzupelnij(tab, n);
    wypisz(tab, n);

    float s = srednia(tab, n);
    wyp("Średnia zarobków pracowników wynosi: ", s);

    float m = mediana(tab, n);
    wyp("Mediana zarobków pracowników wynosi: ", m);

    zarobki(m, s);
    delete[] tab;
    return 0;
}