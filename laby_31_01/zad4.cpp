#include <iostream>
#include <cstdlib>
#include <fstream>
#include <fstream>

using namespace std;

int podajn()
{
    cout << "Podaj n: ";
    int n = 0;
    cin >> n;
    return n;
}

int podajm()
{
    cout << "Podaj m: ";
    int m = 0;
    cin >> m;
    return m;
}

int podajk()
{
    cout << "Podaj k: ";
    int k = 0;
    cin >> k;
    return k;
}

int **ret_tab(int n, int m)
{
    int **tab = new int *[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = new int[m];
    }
    return tab;
}

void losuj(int **tab, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tab[i][j] = rand() % 10;
            cout << tab[i][j] << " ";
        }
        cout << '\n';
    }
}

void zapis(int **tab, int n, int m, int k)
{
    fstream plik;
    plik.open("zad4.dat", ::ios::binary | ::ios::out);
    if (!plik.good())
    {
        cout << "Błąd z plikiem.";
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tab[i][j] % k == 0)
            {
                plik.write(reinterpret_cast<char *>(&tab[i][j]), sizeof(tab[i][j]));
            }
        }
    }
    plik.close();
}

void odczytaj()
{
    fstream plik;
    plik.open("zad4.dat", ios::binary | ios::in);
    if (!plik.good())
    {
        cout << "Błąd z plikiem.";
        exit(-1);
    }
    plik.seekg(0, ios::end);
    streamsize dlugosc_pliku = plik.tellg();
    plik.seekg(0);

    int *tab1 = new int[dlugosc_pliku];

    int m = 0;
    int k = 0;

    while ((k = plik.get()) != EOF)
    {
        tab1[m] = k;
        m++;
    }

    cout << '\n';

    for (int i = 0; i < dlugosc_pliku; i++)
    {
        cout << tab1[i] << " ";
    }

    delete[] tab1;

    plik.close();
}

int main()
{
    setlocale(LC_ALL, "Polish");
    srand(time(NULL));
    int n = podajn();
    int m = podajm();
    int k = podajk();
    int **tab = ret_tab(n, m);
    losuj(tab, n, m);
    zapis(tab, n, m, k);
    odczytaj();
    return 0;
}