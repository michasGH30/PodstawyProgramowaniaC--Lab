#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void zapis_baze(string nazwa)
{
    fstream plik;
    plik.open(nazwa.c_str(), ios::out);
    if (!plik.good())
    {
        cout << "Problem z plikiem!!!!";
        exit(-1);
    }
    int n = 0;
    cout << "Ilu uczniów chcesz zapisać: ";
    cin >> n;
    string imie, nazwisko;
    int rok, nr_grp;
    int w = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Podaj imię: ";
        cin >> imie;
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj rok: ";
        cin >> rok;
        cout << "Podaj numer grupy: ";
        cin >> nr_grp;
        plik << imie << " " << nazwisko << " Rok: " << rok << " Numer grupy: " << nr_grp << " Specjalizacja: ";
        w = 0;
        do
        {
            cout << "Podaj specjalizację:\n1. Programowanie i bazy danych\n2. Systemy i sieci komputerowe\n3. Grafika komputerowa\n4. Bezpieczeństwo systemów komputerowych\n";
            cin >> w;
        } while (w < 1 || w > 4);
        switch (w)
        {
        case 1:
            plik << "Programowanie i bazy danych";
            break;
        case 2:
            plik << "Systemy i sieci komputerowe";
            break;
        case 3:
            plik << "Grafika komputerowa";
            break;
        case 4:
            plik << "Bezpieczeństwo systemów komputerowych";
            break;
        }
        if (i != n - 1)
            plik << '\n';
    }
    plik.close();
}

int main()
{
    setlocale(LC_ALL, "Polish");
    zapis_baze("zadanie1.txt");
    return 0;
}