#include <iostream>
#include <cstdlib>

using namespace std;

class Firma
{
    string nazwa;
    string produkt;
    float w_produktu;
    int n;
    Firma *k;

public:
    Firma()
    {
        nazwa = "PKP";
        produkt = "Pociąg";
        w_produktu = -1;
        n = 0;
    }
    Firma(string naz, string p, float w, Firma *kon, int nK)
    {
        nazwa = naz;
        produkt = p;
        w_produktu = w;
        n = nK;
        k = new Firma[nK];
        for (int i = 0; i < nK; i++)
        {
            k[i] = kon[i];
        }
    }
    void wprowadz()
    {
        cout << "Podaj nazwę: ";
        cin >> nazwa;
        cout << "Podaj nazwę produktu: ";
        cin >> produkt;
        cout << "Podaj wartość produktu: ";
        cin >> w_produktu;
        do
        {
            cout << "Podaj ilość kontrachentów: ";
            cin >> n;
        } while (!(n > 0 && n < 6));
        k = new Firma[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Podaj nazwę kontrachenta: ";
            cin >> k[i].nazwa;
            cout << "Podaj nazwę produktu kontrachenta: ";
            cin >> k[i].produkt;
            cout << "Podaj wartość produktu kontrachenta: ";
            cin >> k[i].w_produktu;
        }
    }

    void dodaj_kontrachenta(Firma kon)
    {
        if (n + 1 > 4)
            return;
        if (n == 0)
        {
            k = new Firma[1];
            k[0] = kon;
            n++;
            return;
        }
        Firma *temp = new Firma[n];
        for (int i = 0; i < n; i++)
        {
            temp[i] = k[i];
        }
        k = new Firma[n + 1];
        for (int i = 0; i < n; i++)
        {
            k[i] = temp[i];
        }
        k[n] = kon;
        n++;
    }

    void czy_jest_firma(string naz)
    {
        for (int i = 0; i < n; i++)
        {
            if (k[i].nazwa == naz)
                cout << "Firma o nazwie: " << k[i].nazwa << " jest kontrachentem\n";
        }
    }

    void licz_wartosc()
    {
        float suma = 0;
        cout << "Produkt firmy: " << nazwa << ", którym jest: " << produkt << ", składa się z komponentów:\n";
        for (int i = 0; i < n; i++)
        {
            suma += k[i].retW();
            cout << k[i].retP() << " od firmy: " << k[i].retN() << ", która sprzedaje go w cenie: " << k[i].retW() << '\n';
        }
        w_produktu = suma;
        cout << "Łączna wartość produktu: " << w_produktu << '\n';
    }

    void wypisz_dane()
    {
        cout << "Firma o nazwie: " << nazwa << " produkuje: " << produkt;
        if (w_produktu == -1)
        {
            cout << ". Jeszcze nie znam ceny\n";
        }
        else
            cout << " w cenie: " << w_produktu;
    }

    void wypisz_dane_firm()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Firma o nazwie: " << k[i].nazwa << " produkuje: " << k[i].produkt << " w cenie: " << k[i].w_produktu << '\n';
        }
    }

    string retP()
    {
        return produkt;
    }

    string retN()
    {
        return nazwa;
    }

    float retW()
    {
        return w_produktu;
    }
};
int main()
{
    setlocale(LC_ALL, "Polish");
    Firma komputer = Firma();
    Firma intel = Firma("Intel", "Procesor Intel", 3124.56, NULL, 0);
    Firma nvidia = Firma("Nvidia", "Karty Graficzne", 2327.23, NULL, 0);
    Firma amd = Firma("AMD", "Procesor AMD", 923.13, NULL, 0);
    komputer.dodaj_kontrachenta(intel);
    komputer.dodaj_kontrachenta(nvidia);
    komputer.dodaj_kontrachenta(amd);
    komputer.wypisz_dane();
    komputer.wypisz_dane_firm();
    komputer.czy_jest_firma("AMD");
    komputer.licz_wartosc();
    komputer.wypisz_dane();
    return 0;
}