#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void uzupelnij(int ***tab, int n, int p)
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                tab[i][j][k] = rand() % 9;
            }
        }
    }
}

void wypisz(int ***tab, int n, int p)
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << tab[i][j][k] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';
}

void wypisz(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
}

int *sumy(int ***tab, int n, int p)
{
    int *temp = new int[p];
    for (int i = 0; i < p; i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k == j)
                    temp[i] += tab[i][j][k];
            }
        }
    }
    return temp;
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int ***tab;
    int n = 0;
    int p = 0;

    do
    {
        cout << "Podaj N: ";
        cin >> n;
    } while (n < 2 || n > 5);

    do
    {
        cout << "Podaj P: ";
        cin >> p;
    } while (p < 2 || p > 5);

    tab = new int **[p];
    for (int i = 0; i < p; i++)
    {
        tab[i] = new int *[n];
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j] = new int[n];
        }
    }

    uzupelnij(tab, n, p);
    wypisz(tab, n, p);
    int *w = sumy(tab, n, p);
    wypisz(w, p);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete[] tab[i][j];
        }
    }
    for (int i = 0; i < p; i++)
    {
        delete[] tab[i];
    }
    delete[] tab;
    return 0;
}