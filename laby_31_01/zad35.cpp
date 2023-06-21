#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int podajn()
{
    cout << "Podaj n: ";
    int n = 0;
    cin >> n;
    return n;
}

int podajk()
{
    cout << "Podaj k: ";
    int k = 0;
    cin >> k;
    return k;
}

char *ret_tab(int n)
{
    char *tab = new char[n];
    return tab;
}

void uzupelnij(char *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Podaj znak: ";
        cin >> tab[i];
    }
}

void zapis(char *tab, int n)
{
    fstream plik;
    plik.open("zad35.dat", ::ios::binary | ::ios::out);
    if (!plik.good())
    {
        cout << "Błąd z plikiem binarnym przy zapisie.";
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        plik.write(reinterpret_cast<char *>(&tab[i]), sizeof(tab[i]));
    }
    plik.close();
}

void odczyt()
{
    cout << "Odczytanie pliku:\n";
    fstream plik;
    plik.open("zad35.dat", ::ios::binary | ::ios::in);
    char znak;
    while (!plik.eof())
    {
        plik.read(reinterpret_cast<char *>(&znak), sizeof(znak));
        if (plik.eof())
        {
            break;
        }
        cout << znak;
    }
    plik.close();
}

void zamien(int k)
{
    cout << "\nZamiana danego znaku w pliku:\n";
    fstream plik;
    plik.open("zad35.dat", ios::binary | ios::out | ios::in);
    char znak;
    cout << "Podaj znak do zamiany: ";
    cin >> znak;

    char temp;
    plik.seekg(k * sizeof(znak));
    plik.read(reinterpret_cast<char *>(&temp), sizeof(temp));
    cout << "k-ty element: " << temp << '\n';

    plik.seekp(k * sizeof(znak));
    plik.write(reinterpret_cast<char *>(&znak), sizeof(znak));
    plik.close();
}

int main()
{
    setlocale(LC_ALL, "Polish");
    int n = podajn();
    int k = podajk();
    char *tab = ret_tab(n);
    uzupelnij(tab, n);
    zapis(tab, n);
    odczyt();
    zamien(k);
    odczyt();
    return 0;
}